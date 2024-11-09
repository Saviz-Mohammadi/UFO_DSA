#ifndef _Queue_
#define _Queue_

#include <iostream>
#include <stdexcept>

namespace ufo
{
    template<typename T>
    class Queue
    {
    private:
        struct Node
        {
            T m_value;
            Node* m_next;

            Node(const T& p_value = T(), Node* p_next = nullptr) :
                m_value(p_value), m_next(p_next)
                {
                    // Nothing...
                };

            ~Node()
                {
                    // Nothing...
                };
        };

    private:
        std::size_t m_size = 0;
        Node* m_front = nullptr;
        Node* m_back = nullptr;

    public:
        Queue() :
            m_size(0),
            m_front(nullptr),
            m_back(nullptr)
            {
                // Nothing...
            };

        // Copy constructor
        Queue(const Queue& other) : m_size(0), m_front(nullptr), m_back(nullptr)
        {
            Node* current = other.m_front;
            while (current != nullptr)
            {
                enqueue(current->m_value);
                current = current->m_next;
            }
        }

        // Copy assignment operator
        Queue& operator=(const Queue& other)
        {
            if (this != &other)
            {
                // Clear the current queue
                while (!is_empty())
                {
                    dequeue();
                }

                // Copy elements from the other queue
                Node* current = other.m_front;
                while (current != nullptr)
                {
                    enqueue(current->m_value);
                    current = current->m_next;
                }
            }
            return *this;
        }

        ~Queue()
        {
            // Free memory...
            while (m_front != nullptr)
            {
                Node* temp = m_front;
                m_front = m_front->m_next;
                delete temp;
            }
        };

    public:
        int size() const
        {
            return m_size;
        };

        void enqueue(const T &item)
        {
            Node* new_node = new Node(item);

            if(is_empty())
            {
                m_front = new_node;
                m_back = new_node;

                ++m_size;

                return;  // Exit immediately after setting m_front and m_back
            }

            ++m_size;

            // At this point, we can assume m_back is not nullptr
            m_back->m_next = new_node;
            m_back = new_node;
        };


        const T& front() const
        {
            if(is_empty())
            {
                throw std::runtime_error("front: queue is empty");
            }
            return m_front->m_value;
        };

        void dequeue()
        {
            if(is_empty())
            {
                throw std::runtime_error("dequeue: queue is empty");
            }

            Node* l_temp = m_front;
            m_front = m_front->m_next;
            delete l_temp;
            --m_size;

            if (m_front == nullptr)  // Queue became empty
                m_back = nullptr;
        };

        bool is_empty() const noexcept
        {
            return (m_size == 0);
        };

        // Comparison operators
        bool operator==(const Queue& other) const
        {
            if (m_size != other.m_size)
                return false;

            Node* this_node = m_front;
            Node* other_node = other.m_front;
            while (this_node != nullptr && other_node != nullptr)
            {
                if (this_node->m_value != other_node->m_value)
                    return false;
                this_node = this_node->m_next;
                other_node = other_node->m_next;
            }
            return true;
        }

        bool operator!=(const Queue& other) const
        {
            return !(*this == other);
        }

        bool operator<(const Queue& other) const
        {
            Node* this_node = m_front;
            Node* other_node = other.m_front;
            while (this_node != nullptr && other_node != nullptr)
            {
                if (this_node->m_value < other_node->m_value)
                    return true;
                if (this_node->m_value > other_node->m_value)
                    return false;
                this_node = this_node->m_next;
                other_node = other_node->m_next;
            }
            return m_size < other.m_size;
        }

        bool operator>(const Queue& other) const
        {
            return other < *this;
        }

        bool operator<=(const Queue& other) const
        {
            return !(other < *this);
        }

        bool operator>=(const Queue& other) const
        {
            return !(*this < other);
        }

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Queue& queue)
        {
            Node* current = queue.m_front;
            os << "Queue(";
            while (current != nullptr)
            {
                os << current->m_value;
                current = current->m_next;
                if (current != nullptr)
                    os << " -> ";
            }
            os << ")";
            return os;
        }

        // Input operator
        friend std::istream& operator>>(std::istream& is, Queue& queue)
        {
            T value;
            queue = Queue(); // Clear the queue

            while (is >> value)
            {
                queue.enqueue(value);
            }
            return is;
        }
    };
} // namespace ufo

#endif // _Queue_
