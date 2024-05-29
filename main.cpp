#include <iostream>
#include <random>
#include <chrono>
#include <string>

#include "Algebraic_hashing_chain.cpp"
#include "Algebraic_hashing_open_addressing.cpp"

#include "Fibonacci_hashing_chain.cpp"
#include "Fibonacci_open_addressing.cpp"

#include "Modulo_hashing_chain.cpp"
#include "Modulo_hashing_open_addressing.cpp"

using namespace std;

const int NUM_ELEMENTS = 1000;

auto totalDuration1_1 = chrono::duration<double, nano>(0);

auto start1 = chrono::high_resolution_clock::now();
auto end1 = chrono::high_resolution_clock::now();
totalDuration1_1 += end1 - start1;

void testHashTable() {
    // Przygotowanie danych
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);

    vector<int> keys;
    vector<string> values;

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        keys.push_back(dis(gen));
        values.push_back("Value_" + to_string(keys.back()));
    }

    // Testowanie Algebraic_hashing_chain
    Algebraic_hashing_chain<int, string> algebraic_hashing_chain;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        algebraic_hashing_chain.add(keys[i], values[i]);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Algebraic_hashing_chain add duration: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        string value;
        algebraic_hashing_chain.find(keys[i], value);
    }
    stop = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Algebraic_hashing_chain find duration: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        algebraic_hashing_chain.remove(keys[i]);
    }
    stop = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Algebraic_hashing_chain remove duration: " << duration.count() << " microseconds" << endl;

    // Testowanie Modulo_hashing_chain
    Modulo_hashing_chain<int, string> modulo_hashing_chain;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        modulo_hashing_chain.add(keys[i], values[i]);
    }
    stop = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Modulo_hashing_chain add duration: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        string value;
        modulo_hashing_chain.find(keys[i], value);
    }
    stop = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Modulo_hashing_chain find duration: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        modulo_hashing_chain.remove(keys[i]);
    }
    stop = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Modulo_hashing_chain remove duration: " << duration.count() << " microseconds" << endl;

    // Testowanie Fibonacci_hashing_chain
    Fibonacci_hashing_chain<int, string> fibonacci_hashing_chain;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        fibonacci_hashing_chain.add(keys[i], values[i]);
    }
    stop = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Fibonacci_hashing_chain add duration: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        string value;
        fibonacci_hashing_chain.find(keys[i], value);
    }
    stop = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Fibonacci_hashing_chain find duration: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        fibonacci_hashing_chain.remove(keys[i]);
    }
    stop = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Fibonacci_hashing_chain remove duration: " << duration.count() << " microseconds" << endl;
}

int main() {
    testHashTable();
    return 0;
}





