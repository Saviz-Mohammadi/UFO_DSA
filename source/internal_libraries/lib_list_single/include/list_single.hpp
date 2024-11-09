#ifndef _ListSingle_
#define _ListSingle_

#include <iostream>

namespace ufo
{
    template<typename T>
    class ListSingle
    {
    private:
        struct Node
        {
        private:
            T m_value;
            Node* m_next;

        public:
            Node(const T& p_value = T(), Node* p_next = nullptr);
            Node(const Node& p_other);
            Node& operator=(const Node& p_other);
            ~Node();

        public:
            T& value() noexcept;
            const T& value() const noexcept;

            Node* next() noexcept;
            const Node* next() const noexcept;
            void next(Node* p_next);
        };

    private:
        Node* m_head;

    public:
        ListSingle();
        ListSingle(const ListSingle<T>& p_other);
        ListSingle<T>& operator=(const ListSingle<T>& p_other);
        ~ListSingle();

    public:
        void append(const T& p_value);
        void prepend(const T& p_value);
        void insert_after(const T& p_target, const T& p_value);

        void pop_front();
        void pop_target(const T& p_target);

        void update(const T& p_target, const T& p_value);
        void front();
        void back();

        bool contains(const T& p_value);
        bool is_empty();

        void clear(); // Added clear function to free memory

        void reverse(); // Reverse function
        void sort();    // Sort function

        // << operator for ListSingle
        friend std::ostream& operator<<(std::ostream& out, const ListSingle<T>& list)
        {
            typename ListSingle<T>::Node* current_Node = list.m_head;

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

        // >> operator for ListSingle
        friend std::istream& operator>>(std::istream& in, ListSingle<T>& list)
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
    ListSingle<T>::Node::Node(const T& p_value, Node* p_next)
        : m_value(p_value), m_next(p_next) {}

    template<typename T>
    ListSingle<T>::Node::Node(const Node& p_other)
        : m_value(p_other.value()), m_next(p_other.next()) {}

    template<typename T>
    typename ListSingle<T>::Node& ListSingle<T>::Node::operator=(const typename ListSingle<T>::Node& p_other)
    {
        m_value = p_other.value();
        m_next = p_other.next();
        return *this;
    }

    template<typename T>
    ListSingle<T>::Node::~Node() {}

    template<typename T>
    T& ListSingle<T>::Node::value() noexcept
    {
        return m_value;
    }

    template<typename T>
    const T& ListSingle<T>::Node::value() const noexcept
    {
        return m_value;
    }

    template<typename T>
    typename ListSingle<T>::Node* ListSingle<T>::Node::next() noexcept
    {
        return m_next;
    }

    template<typename T>
    const typename ListSingle<T>::Node* ListSingle<T>::Node::next() const noexcept
    {
        return m_next;
    }

    template<typename T>
    void ListSingle<T>::Node::next(Node* p_next)
    {
        m_next = p_next;
    }

    // ListSingle Implementation

    template<typename T>
    ListSingle<T>::ListSingle() : m_head(nullptr) {}

    template<typename T>
    ListSingle<T>::ListSingle(const ListSingle<T>& p_other) : m_head(nullptr)
    {
        Node* current_Node = p_other.m_head;
        while (current_Node != nullptr)
        {
            append(current_Node->value());
            current_Node = current_Node->next();
        }
    }

    template<typename T>
    ListSingle<T>& ListSingle<T>::operator=(const ListSingle<T>& p_other)
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
    ListSingle<T>::~ListSingle()
    {
        clear();
    }

    template<typename T>
    void ListSingle<T>::clear()
    {
        while (m_head != nullptr)
        {
            pop_front();
        }
    }

    template<typename T>
    void ListSingle<T>::append(const T& p_value)
    {
        Node* new_Node = new Node(p_value);

        if (m_head == nullptr)
        {
            m_head = new_Node;
            return;
        }

        Node* current_Node = m_head;
        while (current_Node->next() != nullptr)
        {
            current_Node = current_Node->next();
        }

        current_Node->next(new_Node);
    }

    template<typename T>
    void ListSingle<T>::prepend(const T& p_value)
    {
        Node* new_Node = new Node(p_value, m_head);
        m_head = new_Node;
    }

    template<typename T>
    void ListSingle<T>::insert_after(const T& p_target, const T& p_value)
    {
        Node* target_Node = m_head;

        while (target_Node != nullptr)
        {
            if (target_Node->value() == p_target)
            {
                break;
            }
            target_Node = target_Node->next();
        }

        if (target_Node == nullptr)
        {
            return; // Target not found
        }

        Node* new_Node = new Node(p_value, target_Node->next());
        target_Node->next(new_Node);
    }

    template<typename T>
    void ListSingle<T>::pop_front()
    {
        if (m_head == nullptr)
        {
            return;
        }

        Node* temp = m_head;
        m_head = m_head->next();
        delete temp;
    }

    template<typename T>
    void ListSingle<T>::pop_target(const T& p_target)
    {
        if (m_head == nullptr)
        {
            return;
        }

        if (m_head->value() == p_target)
        {
            pop_front();
            return;
        }

        Node* current_Node = m_head;
        while (current_Node->next() != nullptr)
        {
            if (current_Node->next()->value() == p_target)
            {
                Node* temp = current_Node->next();
                current_Node->next(current_Node->next()->next());
                delete temp;
                return;
            }
            current_Node = current_Node->next();
        }
    }

    template<typename T>
    void ListSingle<T>::front()
    {
        if (m_head != nullptr)
        {
            std::cout << m_head->value() << std::endl;
        }
    }

    template<typename T>
    void ListSingle<T>::back()
    {
        if (m_head != nullptr)
        {
            Node* current_Node = m_head;
            while (current_Node->next() != nullptr)
            {
                current_Node = current_Node->next();
            }
            std::cout << current_Node->value() << std::endl;
        }
    }

    template<typename T>
    bool ListSingle<T>::contains(const T& p_value)
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
    bool ListSingle<T>::is_empty()
    {
        return m_head == nullptr;
    }

    template<typename T>
    void ListSingle<T>::reverse()
    {
        Node* prev = nullptr;
        Node* current = m_head;
        Node* next = nullptr;

        while (current != nullptr)
        {
            next = current->next();
            current->next(prev);
            prev = current;
            current = next;
        }
        m_head = prev;
    }

    template<typename T>
    void ListSingle<T>::sort()
    {
        if (!m_head || !m_head->next())
        {
            return; // List is empty or has only one element
        }

        bool swapped;
        do
        {
            swapped = false;
            Node* current = m_head;

            while (current->next() != nullptr)
            {
                if (current->value() > current->next()->value())
                {
                    std::swap(current->value(), current->next()->value());
                    swapped = true;
                }
                current = current->next();
            }
        } while (swapped);
    }

} // namespace ufo

#endif // _ListSingle_
