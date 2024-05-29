#include <iostream>
#include <vector>
#include <optional>
#include <functional>

using namespace std;

template <typename K, typename V>
class Modulo_hashing_open_addressing {
private:
    struct HashNode {
        K key;
        V value;
        bool occupied;

        HashNode(const K& key, const V& value) : key(key), value(value), occupied(true) {}
    };

    vector<optional<HashNode>> table;
    size_t currentSize;
    size_t capacity;
    float loadFactor;

    size_t hashFunction(const K& key) const {
        return key % capacity;
    }

    void rehash() {
        size_t newCapacity = capacity * 2;
        vector<optional<HashNode>> newTable(newCapacity);

        for (const auto& node : table) {
            if (node.has_value() && node->occupied) {
                size_t newIndex = node->key % newCapacity;
                while (newTable[newIndex].has_value() && newTable[newIndex]->occupied) {
                    newIndex = (newIndex + 1) % newCapacity;
                }
                newTable[newIndex] = node;
            }
        }

        table = move(newTable);
        capacity = newCapacity;
    }

public:
    Modulo_hashing_open_addressing(size_t initialCapacity = 16, float loadFactor = 0.75)
            : table(initialCapacity), currentSize(0), capacity(initialCapacity), loadFactor(loadFactor) {}

    void add(const K& key, const V& value) {
        if ((float)currentSize / capacity > loadFactor) {
            rehash();
        }

        size_t index = hashFunction(key);
        while (table[index].has_value() && table[index]->occupied) {
            if (table[index]->key == key) {
                table[index]->value = value;
                return;
            }
            index = (index + 1) % capacity;
        }

        table[index] = HashNode(key, value);
        currentSize++;
    }

    bool remove(const K& key) {
        size_t index = hashFunction(key);
        while (table[index].has_value()) {
            if (table[index]->occupied && table[index]->key == key) {
                table[index]->occupied = false;
                currentSize--;
                return true;
            }
            index = (index + 1) % capacity;
        }
        return false;
    }

    bool find(const K& key, V& value) {
        size_t index = hashFunction(key);
        while (table[index].has_value()) {
            if (table[index]->occupied && table[index]->key == key) {
                value = table[index]->value;
                return true;
            }
            index = (index + 1) % capacity;
        }
        return false;
    }
};

