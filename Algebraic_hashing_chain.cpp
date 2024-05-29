#include <iostream>
#include <vector>
#include <list>
#include <functional>

using namespace std;

template <typename K, typename V>
class Algebraic_hashing_chain {
private:
    vector<list<pair<K, V>>> table;
    hash<K> hashFunction;
    size_t currentSize;
    size_t capacity;
    float loadFactor;

    void rehash() {
        size_t newCapacity = capacity * 2;
        vector<list<pair<K, V>>> newTable(newCapacity);

        for (const auto& bucket : table) {
            for (const auto& element : bucket) {
                size_t newIndex = hashFunction(element.first) % newCapacity;
                newTable[newIndex].push_back(element);
            }
        }

        table = move(newTable);
        capacity = newCapacity;
    }

public:
    Algebraic_hashing_chain(size_t initialCapacity = 16, float loadFactor = 0.75)
            : table(initialCapacity), currentSize(0), capacity(initialCapacity), loadFactor(loadFactor) {}

    void add(const K& key, const V& value) {
        if ((float)currentSize / capacity > loadFactor) {
            rehash();
        }

        size_t index = hashFunction(key) % capacity;
        for (auto& element : table[index]) {
            if (element.first == key) {
                element.second = value;
                return;
            }
        }

        table[index].emplace_back(key, value);
        currentSize++;
    }

    bool remove(const K& key) {
        size_t index = hashFunction(key) % capacity;
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                currentSize--;
                return true;
            }
        }
        return false;
    }

    bool find(const K& key, V& value) {
        size_t index = hashFunction(key) % capacity;
        for (const auto& element : table[index]) {
            if (element.first == key) {
                value = element.second;
                return true;
            }
        }
        return false;
    }
};

