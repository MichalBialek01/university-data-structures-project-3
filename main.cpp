#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <vector>


#include "Algebraic_hashing_chain.cpp"
#include "Algebraic_hashing_open_addressing.cpp"

#include "Fibonacci_hashing_chain.cpp"
#include "Fibonacci_open_addressing.cpp"

#include "Modulo_hashing_chain.cpp"
#include "Modulo_hashing_open_addressing.cpp"

using namespace std;
using namespace std::chrono;

const int NUM_ELEMENTS = 100000;

void testChainHashTables() {
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
    auto totalDuration1_1 = chrono::duration<double, micro >(0);
    auto totalDuration1_2 = chrono::duration<double, micro >(0);
    auto totalDuration1_3 = chrono::duration<double, micro >(0);

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        algebraic_hashing_chain.add(keys[i], values[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration1_1 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        string value;
        algebraic_hashing_chain.find(keys[i], value);
        auto end1 = high_resolution_clock::now();
        totalDuration1_2 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        algebraic_hashing_chain.remove(keys[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration1_3 += end1 - start1;
    }

    cout << "Algebraic_hashing_chain add duration: " << totalDuration1_1.count() << " micro seconds" << endl;
    cout << "Algebraic_hashing_chain find duration: " << totalDuration1_2.count() << " micro seconds" << endl;
    cout << "Algebraic_hashing_chain remove duration: " << totalDuration1_3.count() << " micro seconds" << endl;
    cout<<endl;

    // Testowanie Modulo_hashing_chain
    Modulo_hashing_chain<int, string> modulo_hashing_chain;
    auto totalDuration2_1 = chrono::duration<double, micro >(0);
    auto totalDuration2_2 = chrono::duration<double, micro >(0);
    auto totalDuration2_3 = chrono::duration<double, micro >(0);

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        modulo_hashing_chain.add(keys[i], values[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration2_1 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        string value;
        modulo_hashing_chain.find(keys[i], value);
        auto end1 = high_resolution_clock::now();
        totalDuration2_2 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        modulo_hashing_chain.remove(keys[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration2_3 += end1 - start1;
    }

    cout << "Modulo_hashing_chain add duration: " << totalDuration2_1.count() << " micro seconds" << endl;
    cout << "Modulo_hashing_chain find duration: " << totalDuration2_2.count() << " micro seconds" << endl;
    cout << "Modulo_hashing_chain remove duration: " << totalDuration2_3.count() << " micro seconds" << endl;
    cout<<endl;

    // Testowanie Fibonacci_hashing_chain
    Fibonacci_hashing_chain<int, string> fibonacci_hashing_chain;
    auto totalDuration3_1 = chrono::duration<double, micro >(0);
    auto totalDuration3_2 = chrono::duration<double, micro >(0);
    auto totalDuration3_3 = chrono::duration<double, micro >(0);

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        fibonacci_hashing_chain.add(keys[i], values[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration3_1 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        string value;
        fibonacci_hashing_chain.find(keys[i], value);
        auto end1 = high_resolution_clock::now();
        totalDuration3_2 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        fibonacci_hashing_chain.remove(keys[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration3_3 += end1 - start1;
    }

    cout << "Fibonacci_hashing_chain add duration: " << totalDuration3_1.count() << " micro seconds" << endl;
    cout << "Fibonacci_hashing_chain find duration: " << totalDuration3_2.count() << " micro seconds" << endl;
    cout << "Fibonacci_hashing_chain remove duration: " << totalDuration3_3.count() << " micro seconds" << endl;
    cout<<endl;
}

void testOpenAddressingHashTables() {
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

    // Testowanie Algebraic_hashing_open_addressing
    Algebraic_hashing_open_addressing<int, string> algebraic_hashing_open_addressing;
    auto totalDuration4_1 = chrono::duration<double, micro >(0);
    auto totalDuration4_2 = chrono::duration<double, micro >(0);
    auto totalDuration4_3 = chrono::duration<double, micro >(0);

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        algebraic_hashing_open_addressing.add(keys[i], values[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration4_1 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        string value;
        algebraic_hashing_open_addressing.find(keys[i], value);
        auto end1 = high_resolution_clock::now();
        totalDuration4_2 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        algebraic_hashing_open_addressing.remove(keys[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration4_3 += end1 - start1;
    }

    cout << "Algebraic_hashing_open_addressing add duration: " << totalDuration4_1.count() << " micro seconds" << endl;
    cout << "Algebraic_hashing_open_addressing find duration: " << totalDuration4_2.count() << " micro seconds" << endl;
    cout << "Algebraic_hashing_open_addressing remove duration: " << totalDuration4_3.count() << " micro seconds" << endl;
    cout<<endl;

    // Testowanie Modulo_hashing_open_addressing
    Modulo_hashing_open_addressing<int, string> modulo_hashing_open_addressing;
    auto totalDuration5_1 = chrono::duration<double, micro >(0);
    auto totalDuration5_2 = chrono::duration<double, micro >(0);
    auto totalDuration5_3 = chrono::duration<double, micro >(0);

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        modulo_hashing_open_addressing.add(keys[i], values[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration5_1 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        string value;
        modulo_hashing_open_addressing.find(keys[i], value);
        auto end1 = high_resolution_clock::now();
        totalDuration5_2 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        modulo_hashing_open_addressing.remove(keys[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration5_3 += end1 - start1;
    }

    cout << "Modulo_hashing_open_addressing add duration: " << totalDuration5_1.count() << " micro seconds" << endl;
    cout << "Modulo_hashing_open_addressing find duration: " << totalDuration5_2.count() << " micro seconds" << endl;
    cout << "Modulo_hashing_open_addressing remove duration: " << totalDuration5_3.count() << " micro seconds" << endl;
    cout<<endl;

    // Testowanie Fibonacci_hashing_open_addressing
    Fibonacci_open_addressing<int, string> fibonacci_open_addressing;
    auto totalDuration6_1 = chrono::duration<double, micro >(0);
    auto totalDuration6_2 = chrono::duration<double, micro >(0);
    auto totalDuration6_3 = chrono::duration<double, micro >(0);

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        fibonacci_open_addressing.add(keys[i], values[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration6_1 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        string value;
        fibonacci_open_addressing.find(keys[i], value);
        auto end1 = high_resolution_clock::now();
        totalDuration6_2 += end1 - start1;
    }

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        auto start1 = high_resolution_clock::now();
        fibonacci_open_addressing.remove(keys[i]);
        auto end1 = high_resolution_clock::now();
        totalDuration6_3 += end1 - start1;
    }

    cout << "Fibonacci_hashing_open_addressing add duration: " << totalDuration6_1.count() << " micro seconds" << endl;
    cout << "Fibonacci_hashing_open_addressing find duration: " << totalDuration6_2.count() << " micro seconds" << endl;
    cout << "Fibonacci_hashing_open_addressing remove duration: " << totalDuration6_3.count() << " micro seconds" << endl;
    cout<<endl;
}

int main() {
    testChainHashTables();
    cout<<endl;
    testOpenAddressingHashTables();
    return 0;
}
