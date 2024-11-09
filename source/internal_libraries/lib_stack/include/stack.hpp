#ifndef _Stack_
#define _Stack_

#include <iostream>
#include <stdexcept>

#include <iostream>
#include <stdexcept>

namespace ufo
{
    template<typename T>
    class Stack
    {
    private:
        struct Node {
            T data;
            Node* next;
            Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
        };

        Node* m_top;   // Pointer to the top node
        std::size_t m_size;

        void copy_from(const Stack& other)
        {
            if (!other.m_top) return;
            m_top = new Node(other.m_top->data);
            Node* current_other = other.m_top->next;
            Node* current_this = m_top;

            while (current_other)
            {
                current_this->next = new Node(current_other->data);
                current_this = current_this->next;
                current_other = current_other->next;
            }
            m_size = other.m_size;
        }

    public:

        void clear()
        {
            while (m_top) {
                Node* temp = m_top;
                m_top = m_top->next;
                delete temp;
            }
            m_size = 0;
        }

    public:
        Stack() : m_top(nullptr), m_size(0) {}

        Stack(const Stack& other) : m_top(nullptr), m_size(0)
        {
            copy_from(other);
        }

        ~Stack()
        {
            clear();
        }

        Stack& operator=(const Stack& other)
        {
            if (this != &other)
            {
                clear();
                copy_from(other);
            }
            return *this;
        }

        void push(const T& data)
        {
            m_top = new Node(data, m_top);
            ++m_size;
        }

        T pop()
        {
            if (is_empty())
                throw std::out_of_range("Stack is empty");

            Node* temp = m_top;
            T data = m_top->data;
            m_top = m_top->next;
            delete temp;
            --m_size;
            return data;
        }

        const T peek() const
        {
            if (is_empty())
                throw std::out_of_range("Stack is empty");
            return m_top->data;
        }

        bool is_empty() const
        {
            return m_top == nullptr;
        }

        std::size_t size() const
        {
            return m_size;
        }

        // Comparison operators
        bool operator==(const Stack& other) const
        {
            if (m_size != other.m_size) return false;
            Node* current_this = m_top;
            Node* current_other = other.m_top;
            while (current_this && current_other)
            {
                if (current_this->data != current_other->data)
                    return false;
                current_this = current_this->next;
                current_other = current_other->next;
            }
            return true;
        }

        bool operator!=(const Stack& other) const
        {
            return !(*this == other);
        }

        bool operator<(const Stack& other) const
        {
            Node* current_this = m_top;
            Node* current_other = other.m_top;
            while (current_this && current_other)
            {
                if (current_this->data < current_other->data) return true;
                if (current_this->data > current_other->data) return false;
                current_this = current_this->next;
                current_other = current_other->next;
            }
            return m_size < other.m_size;
        }

        bool operator>(const Stack& other) const
        {
            return other < *this;
        }

        bool operator<=(const Stack& other) const
        {
            return !(*this > other);
        }

        bool operator>=(const Stack& other) const
        {
            return !(*this < other);
        }

        // Stream operators
        friend std::ostream& operator<<(std::ostream& os, const Stack& stack)
        {
            Node* current = stack.m_top;
            os << "Stack(top -> bottom): ";
            while (current)
            {
                os << current->data << " ";
                current = current->next;
            }
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Stack& stack)
        {
            T value;
            is >> value;
            stack.push(value);
            return is;
        }
    };
}


#endif // _Stack_
