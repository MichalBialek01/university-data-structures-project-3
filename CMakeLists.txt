cmake_minimum_required(VERSION 3.27)
project(HashTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashTable main.cpp
        Algebraic_hashing_chain.cpp
        Algebraic_hashing_open_addressing.cpp
        Fibonacci_hashing_chain.cpp
        Fibonacci_open_addressing.cpp
        Modulo_hashing_chain.cpp
        Modulo_hashing_open_addressing.cpp
)
