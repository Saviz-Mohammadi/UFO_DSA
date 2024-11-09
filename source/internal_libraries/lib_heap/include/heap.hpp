#ifndef UFO_MAX_HEAP_HPP
#define UFO_MAX_HEAP_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

namespace ufo {

    template <typename T>
    class MaxHeap {
    public:
        MaxHeap() = default;

        // Inserts an element into the heap
        void insert(const T& value) {
            data.push_back(value);
            heapifyUp(data.size() - 1);
        }

        // Returns the maximum element
        T getMax() const {
            if (data.empty()) {
                throw std::out_of_range("Heap is empty");
            }
            return data[0];
        }

        // Removes and returns the maximum element
        T extractMax() {
            if (data.empty()) {
                throw std::out_of_range("Heap is empty");
            }

            T maxValue = data[0];
            data[0] = data.back();
            data.pop_back();
            if (!data.empty()) {
                heapifyDown(0);
            }
            return maxValue;
        }

        // Returns true if the heap is empty
        bool isEmpty() const {
            return data.empty();
        }

        // Returns the number of elements in the heap
        size_t size() const {
            return data.size();
        }

        // Comparison operators
        bool operator==(const MaxHeap& other) const {
            return data == other.data;
        }

        bool operator!=(const MaxHeap& other) const {
            return data != other.data;
        }

        bool operator<(const MaxHeap& other) const {
            return data < other.data;
        }

        bool operator<=(const MaxHeap& other) const {
            return data <= other.data;
        }

        bool operator>(const MaxHeap& other) const {
            return data > other.data;
        }

        bool operator>=(const MaxHeap& other) const {
            return data >= other.data;
        }

        // Stream insertion operator
        friend std::ostream& operator<<(std::ostream& os, const MaxHeap& heap) {
            os << "[ ";
            for (const auto& elem : heap.data) {
                os << elem << " ";
            }
            os << "]";
            return os;
        }

        // Stream extraction operator
        friend std::istream& operator>>(std::istream& is, MaxHeap& heap) {
            T value;
            while (is >> value) {
                heap.insert(value);
            }
            return is;
        }

    private:
        std::vector<T> data;

        // Helper function to maintain the max-heap property from a given index upwards
        void heapifyUp(size_t index) {
            while (index > 0) {
                size_t parentIndex = (index - 1) / 2;
                if (data[index] <= data[parentIndex]) {
                    break;
                }
                std::swap(data[index], data[parentIndex]);
                index = parentIndex;
            }
        }

        // Helper function to maintain the max-heap property from a given index downwards
        void heapifyDown(size_t index) {
            size_t leftChild;
            size_t rightChild;
            size_t largest = index;

            while (true) {
                leftChild = 2 * index + 1;
                rightChild = 2 * index + 2;

                if (leftChild < data.size() && data[leftChild] > data[largest]) {
                    largest = leftChild;
                }
                if (rightChild < data.size() && data[rightChild] > data[largest]) {
                    largest = rightChild;
                }
                if (largest == index) {
                    break;
                }

                std::swap(data[index], data[largest]);
                index = largest;
            }
        }
    };

} // namespace ufo

#endif // UFO_MAX_HEAP_HPP
