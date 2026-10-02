#pragma once
#include <chrono>
template <typename T>
inline void doNotOptimize(T const& value) {
asm volatile("" : : "r,m"(value) : "memory");
}
class Timer{
    std::chrono::steady_clock::time_point start_;
    public:
    Timer(){
        start_ = std::chrono::steady_clock::now();
    }
    auto reset() {
        start_ = std::chrono::steady_clock::now();
    }
    auto duration() const{
        auto finish_ = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(finish_ - start_).count();
    }
};