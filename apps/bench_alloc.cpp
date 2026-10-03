#include "matrix/timer.hpp"
#include <iostream>
#include "matrix/stack_matrix.hpp"
#include "matrix/heap_matrix.hpp"
int stack(){
    Timer t;
    for (int k = 1; k < 10000000; k *= 2){
        t.reset(); 

        for (int i = 0; i < k; ++i){
            StackMatrix a;
            a.at(6, 7) = 67;
            doNotOptimize(a);
        }
        auto time = t.duration();
        if (time >= 100'000'000){
            std::cout << time << std::endl;
            return k;
        }
    }
    return -1;
}

int heap(std::size_t n){
    Timer t;
    for (int k = 1; k < 100000000; k *= 2){
        t.reset(); 

        for (int i = 0; i < k; ++i){
            HeapMatrix a(n);
            a.at(6, 7) = 67;
            doNotOptimize(a);
        }
        auto time = t.duration();
        if (time >= 100'000'000){
            std::cout << "time: " << time << std::endl;
            return k;
        }
    }
    return -1;
}

int heap2(std::size_t n){
    Timer t;
    for (int k = 1; k < 100000000; k *= 2){
        t.reset(); 

        for (int i = 0; i < k; ++i){
            HeapMatrix a(n, 0);
            a.at(6, 7) = 67;
            doNotOptimize(a);
        }
        auto time = t.duration();
        if (time >= 100'000'000){
            std::cout << "time: " << time << std::endl;
            return k;
        }
    }
    return -1;
}
int main(){
    // std::cout << stack();
    std::cout << "50: " << heap2(50) << std::endl;
    std::cout << "100: " << heap2(100) << std::endl;
    std::cout << "250: " << heap2(250) << std::endl;
    std::cout << "500: " << heap2(500) << std::endl;
    std::cout << "1000: " << heap2(1000) << std::endl;
    std::cout << "2000: " << heap2(2000) << std::endl;
    return 0;
}