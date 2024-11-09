#ifndef UFO_VECTOR_HPP
#define UFO_VECTOR_HPP

#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <iterator>

namespace ufo {

    template <typename T>
    class Vector {
    private:
        T* data;
        size_t size_;
        size_t capacity_;

        // Helper function to resize the internal array
        void resize(size_t new_capacity) {
            T* new_data = new T[new_capacity];
            std::copy(data, data + size_, new_data);
            delete[] data;
            data = new_data;
            capacity_ = new_capacity;
        }

    public:
        // Default constructor
        Vector() : data(nullptr), size_(0), capacity_(0) {}

        // Constructor from initializer list
        Vector(std::initializer_list<T> init) : size_(init.size()), capacity_(init.size()) {
            data = new T[capacity_];
            std::copy(init.begin(), init.end(), data);
        }

        // Copy constructor
        Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
            data = new T[capacity_];
            std::copy(other.data, other.data + size_, data);
        }

        // Move constructor
        Vector(Vector&& other) noexcept : data(other.data), size_(other.size_), capacity_(other.capacity_) {
            other.data = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }

        // Destructor
        ~Vector() {
            delete[] data;
        }

        // Copy assignment operator
        Vector& operator=(const Vector& other) {
            if (this != &other) {
                delete[] data;
                size_ = other.size_;
                capacity_ = other.capacity_;
                data = new T[capacity_];
                std::copy(other.data, other.data + size_, data);
            }
            return *this;
        }

        // Move assignment operator
        Vector& operator=(Vector&& other) noexcept {
            if (this != &other) {
                delete[] data;
                data = other.data;
                size_ = other.size_;
                capacity_ = other.capacity_;
                other.data = nullptr;
                other.size_ = 0;
                other.capacity_ = 0;
            }
            return *this;
        }

        // Access element at index (with bounds checking)
        T& operator[](size_t index) {
            if (index >= size_) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        const T& operator[](size_t index) const {
            if (index >= size_) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        // Push back element (resize if necessary)
        void push_back(const T& value) {
            if (size_ == capacity_) {
                resize(capacity_ == 0 ? 1 : capacity_ * 2);
            }
            data[size_] = value;
            ++size_;
        }

        // Move push back element (avoid copy)
        void push_back(T&& value) {
            if (size_ == capacity_) {
                resize(capacity_ == 0 ? 1 : capacity_ * 2);
            }
            data[size_] = std::move(value);
            ++size_;
        }

        // Pop back element
        void pop_back() {
            if (size_ > 0) {
                --size_;
            } else {
                throw std::out_of_range("Cannot pop from empty vector");
            }
        }

        // Get current size of the vector
        size_t size() const {
            return size_;
        }

        // Get current capacity of the vector
        size_t capacity() const {
            return capacity_;
        }

        // Check if the vector is empty
        bool empty() const {
            return size_ == 0;
        }

        // Comparison operators
        bool operator==(const Vector& other) const {
            return size_ == other.size_ && std::equal(data, data + size_, other.data);
        }

        bool operator!=(const Vector& other) const {
            return !(*this == other);
        }

        bool operator<(const Vector& other) const {
            return std::lexicographical_compare(data, data + size_, other.data, other.data + other.size_);
        }

        bool operator<=(const Vector& other) const {
            return !(*this > other);
        }

        bool operator>(const Vector& other) const {
            return other < *this;
        }

        bool operator>=(const Vector& other) const {
            return !(*this < other);
        }

        // Stream output operator (<<)
        friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
            os << "[";
            for (size_t i = 0; i < vec.size_; ++i) {
                os << vec.data[i];
                if (i != vec.size_ - 1) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }

        // Stream input operator (>>)
        friend std::istream& operator>>(std::istream& is, Vector& vec) {
            T value;
            char ch;
            is >> ch; // Skip the opening bracket
            while (is >> value) {
                vec.push_back(value);
                is >> ch; // Read the comma or closing bracket
                if (ch == ']') {
                    break;
                }
            }
            return is;
        }

        // Iterators (begin and end)
        T* begin() { return data; }
        const T* begin() const { return data; }
        T* end() { return data + size_; }
        const T* end() const { return data + size_; }
    };

} // namespace ufo

#endif // UFO_VECTOR_HPP
