#include <cstddef>  // size_t
#include <random> // mt19937_64
#include <cstdint> // uint64_t
#include <list>
#include <vector>
#include <iostream>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    // test here...
    Timer timer;
    std::mt19937_64 rng(0);

    //List test
    std::list<uint64_t> list;
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i){
        list.push_back(rng());
    }
    uint64_t listinsert_time = timer.click<Timer::Micros>();

    //Vector test
    std::vector<uint64_t> vector;
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i){
        vector.push_back(rng());
    }
    uint64_t vectorinsert_time = timer.click<Timer::Micros>();

    //Reserve vector test
    std::vector<uint64_t> vector_reserve;
    vector_reserve.reserve(SIZE);
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i){
        vector_reserve.push_back(rng());
    }
    uint64_t vectorreserveinsert_time = timer.click<Timer::Micros>();

    uint64_t list_sum = 0;
    timer.restart();
    for (uint64_t value : list) {
        list_sum += value;
    }
    uint64_t listsum_time = timer.click<Timer::Micros>();

    uint64_t vector_sum = 0;
    timer.restart();
    for (uint64_t value : vector) {
        vector_sum += value;
    }
    uint64_t vectorsum_time = timer.click<Timer::Micros>();

    std::cout << "List insert time: " << listinsert_time << " microseconds \n";
    std::cout << "Vector insert time: " << vectorinsert_time << " microseconds \n";
    std::cout << "Vector reserve insert time: " << vectorreserveinsert_time << " microseconds \n";
    std::cout << "List sum and time: " << list_sum << " and " << listsum_time << " microseconds \n";
    std::cout << "Vector sum and time: " << vector_sum << " and " << vectorsum_time << " microseconds \n";
    return 0;
}
