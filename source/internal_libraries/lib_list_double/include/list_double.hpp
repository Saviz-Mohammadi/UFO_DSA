#ifndef _ListDouble_
#define _ListDouble_

#include <iostream>

namespace ufo
{
    template<typename T>
    class ListDouble
    {
    private:
        struct Node
        {
        private:
            T m_value;
            Node* m_next;
            Node* m_prev;

        public:
            Node(const T& p_value = T(), Node* p_next = nullptr, Node* p_prev = nullptr);
            Node(const Node& p_other);
            Node& operator=(const Node& p_other);
            ~Node();

        public:
            T& value() noexcept;
            const T& value() const noexcept;

            Node* next() noexcept;
            const Node* next() const noexcept;
            void next(Node* p_next);

            Node* prev() noexcept;
            const Node* prev() const noexcept;
            void prev(Node* p_prev);
        };

    private:
        Node* m_head;
        Node* m_tail;

    public:
        ListDouble();
        ListDouble(const ListDouble<T>& p_other);
        ListDouble<T>& operator=(const ListDouble<T>& p_other);
        ~ListDouble();

    public:
        void append(const T& p_value);
        void prepend(const T& p_value);
        void insert_after(const T& p_target, const T& p_value);
        void insert_before(const T& p_target, const T& p_value);

        void pop_front();
        void pop_back();
        void pop_target(const T& p_target);

        void update(const T& p_target, const T& p_value);
        void front();
        void back();

        void reverse();
        void sort();

        bool contains(const T& p_value);
        bool is_empty();

        void clear(); // Added clear function to free memory

        // << operator for ListDouble
        friend std::ostream& operator<<(std::ostream& out, const ListDouble<T>& list)
        {
            typename ListDouble<T>::Node* current_Node = list.m_head;

            out << "[";

            while (current_Node != nullptr)
            {
                out << current_Node->value();
                if (current_Node->next() != nullptr)
                {
                    out << ", ";
                }
                current_Node = current_Node->next();
            }

            out << "]";
            return out;
        }

        // >> operator for ListDouble
        friend std::istream& operator>>(std::istream& in, ListDouble<T>& list)
        {
            T value;
            while (in >> value)
            {
                list.append(value);  // Append each value to the list
                if (in.peek() == '\n' || in.peek() == EOF)
                    break;
            }
            return in;
        }
    };

    // Node implementation
    template<typename T>
    ListDouble<T>::Node::Node(const T& p_value, Node* p_next, Node* p_prev)
        : m_value(p_value), m_next(p_next), m_prev(p_prev) {}

    template<typename T>
    ListDouble<T>::Node::Node(const Node& p_other)
        : m_value(p_other.value()), m_next(p_other.next()), m_prev(p_other.prev()) {}

    template<typename T>
    typename ListDouble<T>::Node& ListDouble<T>::Node::operator=(const typename ListDouble<T>::Node& p_other)
    {
        m_value = p_other.value();
        m_next = p_other.next();
        m_prev = p_other.prev();
        return *this;
    }

    template<typename T>
    ListDouble<T>::Node::~Node() {}

    template<typename T>
    T& ListDouble<T>::Node::value() noexcept
    {
        return m_value;
    }

    template<typename T>
    const T& ListDouble<T>::Node::value() const noexcept
    {
        return m_value;
    }

    template<typename T>
    typename ListDouble<T>::Node* ListDouble<T>::Node::next() noexcept
    {
        return m_next;
    }

    template<typename T>
    const typename ListDouble<T>::Node* ListDouble<T>::Node::next() const noexcept
    {
        return m_next;
    }

    template<typename T>
    void ListDouble<T>::Node::next(Node* p_next)
    {
        m_next = p_next;
    }

    template<typename T>
    typename ListDouble<T>::Node* ListDouble<T>::Node::prev() noexcept
    {
        return m_prev;
    }

    template<typename T>
    const typename ListDouble<T>::Node* ListDouble<T>::Node::prev() const noexcept
    {
        return m_prev;
    }

    template<typename T>
    void ListDouble<T>::Node::prev(Node* p_prev)
    {
        m_prev = p_prev;
    }

    // ListDouble Implementation

    template<typename T>
    ListDouble<T>::ListDouble() : m_head(nullptr), m_tail(nullptr) {}

    template<typename T>
    ListDouble<T>::ListDouble(const ListDouble<T>& p_other) : m_head(nullptr), m_tail(nullptr)
    {
        Node* current_Node = p_other.m_head;
        while (current_Node != nullptr)
        {
            append(current_Node->value());
            current_Node = current_Node->next();
        }
    }

    template<typename T>
    ListDouble<T>& ListDouble<T>::operator=(const ListDouble<T>& p_other)
    {
        if (this == &p_other)
        {
            return *this;
        }

        clear(); // Clear the existing list before copying

        Node* current_Node = p_other.m_head;
        while (current_Node != nullptr)
        {
            append(current_Node->value());
            current_Node = current_Node->next();
        }

        return *this;
    }

    template<typename T>
    ListDouble<T>::~ListDouble()
    {
        clear();
    }

    template<typename T>
    void ListDouble<T>::clear()
    {
        while (m_head != nullptr)
        {
            pop_front();
        }
    }

    template<typename T>
    void ListDouble<T>::append(const T& p_value)
    {
        Node* new_Node = new Node(p_value);

        if (m_head == nullptr && m_tail == nullptr)
        {
            m_head = m_tail = new_Node;
            return;
        }

        new_Node->prev(m_tail);   // Set the previous pointer using the setter
        m_tail->next(new_Node);    // Set the next pointer using the setter

        m_tail = new_Node;
    }

    template<typename T>
    void ListDouble<T>::prepend(const T& p_value)
    {
        Node* new_Node = new Node(p_value, m_head);

        if (m_head == nullptr && m_tail == nullptr)
        {
            m_head = m_tail = new_Node;
            return;
        }

        new_Node->next(m_head);   // Fix: Set the next pointer using the setter
        m_head->prev(new_Node);   // Fix: Set the previous pointer using the setter
        m_head = new_Node;
    }

    template<typename T>
    void ListDouble<T>::insert_after(const T& p_target, const T& p_value)
    {
        if (!contains(p_target))
        {
            return;
        }

        Node* target_Node = m_head;

        while (target_Node != nullptr)
        {
            if (target_Node->value() == p_target)
            {
                break;
            }
            target_Node = target_Node->next();
        }

        Node* new_Node = new Node(p_value);

        if (target_Node->next() == nullptr)
        {
            target_Node->next(new_Node);
            new_Node->prev(target_Node);
            m_tail = new_Node;
            return;
        }

        new_Node->next(target_Node->next());
        new_Node->next()->prev(new_Node);
        new_Node->prev(target_Node);
        target_Node->next(new_Node);
    }

    template<typename T>
    void ListDouble<T>::insert_before(const T& p_target, const T& p_value)
    {
        if (!contains(p_target))
        {
            return;
        }

        Node* target_Node = m_head;

        while (target_Node != nullptr)
        {
            if (target_Node->value() == p_target)
            {
                break;
            }
            target_Node = target_Node->next();
        }

        Node* new_Node = new Node(p_value);

        if (target_Node->prev() == nullptr)
        {
            target_Node->prev(new_Node);
            new_Node->next(target_Node);
            m_head = new_Node;
            return;
        }

        new_Node->prev(target_Node->prev());
        new_Node->prev()->next(new_Node);
        new_Node->next(target_Node);
        target_Node->prev(new_Node);
    }

    template<typename T>
    void ListDouble<T>::pop_target(const T& p_target)
    {
        if (!contains(p_target))
        {
            return;
        }

        Node* target_Node = m_head;

        while (target_Node != nullptr)
        {
            if (target_Node->value() == p_target)
            {
                break;
            }
            target_Node = target_Node->next();
        }

        if (target_Node->prev() != nullptr)
        {
            target_Node->prev()->next(target_Node->next());
        }
        else
        {
            m_head = target_Node->next();
        }

        if (target_Node->next() != nullptr)
        {
            target_Node->next()->prev(target_Node->prev());
        }
        else
        {
            m_tail = target_Node->prev();
        }

        delete target_Node;
    }

    template<typename T>
    void ListDouble<T>::pop_front()
    {
        if (m_head == nullptr)
        {
            return;
        }

        Node* temp = m_head;

        if (m_head->next() == nullptr)
        {
            m_head = nullptr;
            m_tail = nullptr;
        }
        else
        {
            m_head = m_head->next();
            m_head->prev(nullptr);
        }

        delete temp;
    }

    template<typename T>
    void ListDouble<T>::pop_back()
    {
        if (m_tail == nullptr)
        {
            return;
        }

        Node* temp = m_tail;

        if (m_tail->prev() == nullptr)
        {
            m_head = nullptr;
            m_tail = nullptr;
        }
        else
        {
            m_tail = m_tail->prev();
            m_tail->next(nullptr);
        }

        delete temp;
    }

    template<typename T>
    void ListDouble<T>::front()
    {
        if (m_head != nullptr)
        {
            std::cout << m_head->value() << std::endl;
        }
    }

    template<typename T>
    void ListDouble<T>::back()
    {
        if (m_tail != nullptr)
        {
            std::cout << m_tail->value() << std::endl;
        }
    }

    template<typename T>
    bool ListDouble<T>::contains(const T& p_value)
    {
        Node* current_Node = m_head;

        while (current_Node != nullptr)
        {
            if (current_Node->value() == p_value)
            {
                return true;
            }
            current_Node = current_Node->next();
        }

        return false;
    }

    template<typename T>
    bool ListDouble<T>::is_empty()
    {
        return m_head == nullptr;
    }

    // Reverse function to reverse the list order
    template<typename T>
    void ListDouble<T>::reverse()
    {
        if (m_head == nullptr || m_head == m_tail)  // Empty or single element list
        {
            return;
        }

        Node* current = m_head;
        Node* temp = nullptr;

        // Traverse the list and reverse the pointers
        while (current != nullptr)
        {
            temp = current->next();
            current->next(current->prev());
            current->prev(temp);
            current = current->prev();  // Move to the next node (which was previously prev)
        }

        // Swap head and tail
        temp = m_head;
        m_head = m_tail;
        m_tail = temp;
    };

    template<typename T>
    void ListDouble<T>::sort()
    {
        if (m_head == nullptr || m_head == m_tail)  // Empty or single element list
        {
            return;
        }

        bool swapped;
        do
        {
            swapped = false;
            Node* current = m_head;

            while (current != nullptr && current->next() != nullptr)
            {
                // If current value is greater than next, swap their values
                if (current->value() > current->next()->value())
                {
                    // Swap the values (no need to use value() setter, just swap)
                    T temp_value = current->value();
                    current->value() = current->next()->value();
                    current->next()->value() = temp_value;

                    swapped = true;
                }
                current = current->next();
            }

        } while (swapped); // Continue sorting until no more swaps
    }


} // namespace ufo

#endif // _ListDouble_
