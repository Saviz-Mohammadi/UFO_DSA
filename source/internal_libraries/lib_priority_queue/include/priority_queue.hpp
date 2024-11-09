#ifndef UFO_PRIORITY_QUEUE_HPP
#define UFO_PRIORITY_QUEUE_HPP

#include "heap.hpp"  // Include your MaxHeap implementation
#include <iostream>

namespace ufo {

    template <typename T>
    class PriorityQueue {
    public:
        PriorityQueue() = default;

        // Inserts an element into the priority queue
        void enqueue(const T& value) {
            maxHeap.insert(value);
        }

        // Removes and returns the element with the highest priority
        T dequeue() {
            return maxHeap.extractMax();
        }

        // Returns the element with the highest priority without removing it
        T peek() const {
            return maxHeap.getMax();
        }

        // Returns true if the priority queue is empty
        bool isEmpty() const {
            return maxHeap.isEmpty();
        }

        // Returns the number of elements in the priority queue
        size_t size() const {
            return maxHeap.size();
        }

        // Comparison operators
        bool operator==(const PriorityQueue& other) const {
            return maxHeap == other.maxHeap;
        }

        bool operator!=(const PriorityQueue& other) const {
            return maxHeap != other.maxHeap;
        }

        bool operator<(const PriorityQueue& other) const {
            return maxHeap < other.maxHeap;
        }

        bool operator<=(const PriorityQueue& other) const {
            return maxHeap <= other.maxHeap;
        }

        bool operator>(const PriorityQueue& other) const {
            return maxHeap > other.maxHeap;
        }

        bool operator>=(const PriorityQueue& other) const {
            return maxHeap >= other.maxHeap;
        }

        // Stream insertion operator
        friend std::ostream& operator<<(std::ostream& os, const PriorityQueue& queue) {
            os << queue.maxHeap;
            return os;
        }

        // Stream extraction operator
        friend std::istream& operator>>(std::istream& is, PriorityQueue& queue) {
            T value;
            while (is >> value) {
                queue.enqueue(value);
            }
            return is;
        }

    private:
        MaxHeap<T> maxHeap;
    };

} // namespace ufo

#endif // UFO_PRIORITY_QUEUE_HPP
