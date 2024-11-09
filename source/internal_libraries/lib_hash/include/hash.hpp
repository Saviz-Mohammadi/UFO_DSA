#ifndef UFO_HASH
#define UFO_HASH

#include <iostream>
#include <list>
#include <vector>
#include <functional>
#include <stdexcept>
#include <sstream>

namespace ufo {

    template <typename Key, typename Value>
    class HashTable {
    private:
        std::vector<std::list<std::pair<Key, Value>>> table;
        size_t num_elements;
        size_t capacity;
        std::hash<Key> hash_fn;

        size_t hash(const Key& key) const {
            return hash_fn(key) % capacity;
        }

    public:
        // Constructor
        HashTable(size_t capacity = 10) : capacity(capacity), num_elements(0) {
            table.resize(capacity);
        }

        // Insert a key-value pair
        void insert(const Key& key, const Value& value) {
            size_t index = hash(key);
            auto& bucket = table[index];

            // Check if the key already exists and update the value if so
            for (auto& pair : bucket) {
                if (pair.first == key) {
                    pair.second = value;
                    return;
                }
            }

            bucket.push_back({key, value});
            num_elements++;
        }

        // Find a value by key
        Value& find(const Key& key) {
            size_t index = hash(key);
            auto& bucket = table[index];

            for (auto& pair : bucket) {
                if (pair.first == key) {
                    return pair.second;
                }
            }

            throw std::out_of_range("Key not found");
        }

        // Check if the table is empty
        bool empty() const {
            return num_elements == 0;
        }

        // Comparison operators
        bool operator==(const HashTable& other) const {
            if (num_elements != other.num_elements) return false;

            for (size_t i = 0; i < capacity; ++i) {
                if (table[i] != other.table[i]) return false;
            }
            return true;
        }

        bool operator!=(const HashTable& other) const {
            return !(*this == other);
        }

        bool operator<(const HashTable& other) const {
            if (num_elements < other.num_elements) return true;
            if (num_elements > other.num_elements) return false;
            return table < other.table; // lexicographical comparison
        }

        bool operator>(const HashTable& other) const {
            return other < *this;
        }

        bool operator<=(const HashTable& other) const {
            return !(other < *this);
        }

        bool operator>=(const HashTable& other) const {
            return !(*this < other);
        }

        // Stream insertion operator (<<)
        friend std::ostream& operator<<(std::ostream& os, const HashTable& ht) {
            os << "{ ";
            bool first = true;
            for (size_t i = 0; i < ht.capacity; ++i) {
                for (const auto& pair : ht.table[i]) {
                    if (!first) {
                        os << ", ";
                    }
                    os << pair.first << ": " << pair.second;
                    first = false;
                }
            }
            os << " }";
            return os;
        }

        // Stream extraction operator (>>)
        friend std::istream& operator>>(std::istream& is, HashTable& ht) {
            char ch;
            is >> ch; // Expect '{'

            if (ch != '{') {
                throw std::invalid_argument("Invalid input format");
            }

            while (is >> ch && ch != '}') {
                if (ch == ',') {
                    is >> ch;
                }
                if (ch != ' ' && ch != ':') {
                    is.putback(ch);
                    Key key;
                    Value value;
                    is >> key >> ch >> value;
                    ht.insert(key, value);
                }
            }

            return is;
        }

    };

}

#endif // UFO_HASH
