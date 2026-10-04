#include "matrix/timer.hpp"
#include <iostream>
#include "matrix/stack_matrix.hpp"
#include "matrix/heap_matrix.hpp"
#include <cmath>
int stack(){
    Timer t;
    for(int i = 0; i < 3; ++i){
        StackMatrix a;
        a.at(6, 7) = 67;
        doNotOptimize(a);
    }
    for (int k = 1; k < 10000000; k *= 2){
        t.reset(); 

        for (int i = 0; i < k; ++i){
            StackMatrix a;
            a.at(6, 7) = 67;
            doNotOptimize(a);
        }
        auto time = t.duration();
        if (time >= 100'000'000){
            std::cout << "B,StackMatrix,500,Release,5,"<< std::round((static_cast<double>(time) / k) * 100.00) / 100.00  << std::endl;
            return 0;
        }
    }
    return -1;
}

int heap(std::size_t n){
    Timer t;
    for(int i = 0; i < 3; ++i){
        HeapMatrix a(n);
        a.at(6, 7) = 67;
        doNotOptimize(a);
    }
    for (int k = 1; k < 100000000; k *= 2){
        t.reset(); 

        for (int i = 0; i < k; ++i){
            HeapMatrix a(n);
            a.at(6, 7) = 67;
            doNotOptimize(a);
        }
        auto time = t.duration();
        if (time >= 100'000'000){
            std::cout << "B,HeapMatrix," << n <<",Release,5," << std::round((static_cast<double>(time) / k) * 100.00) / 100.00  << std::endl;
            return k;
        }
    }
    return -1;
}

int heap2(std::size_t n){
    Timer t;
    for (int i = 0; i < 3; ++i){
        HeapMatrix a(n);
        a.at(6, 7) = 67;
        doNotOptimize(a);
    }
    for (int k = 1; k < 100000000; k *= 2){
        t.reset(); 

        for (int i = 0; i < k; ++i){
            HeapMatrix a(n, 0);
            a.at(6, 7) = 67;
            doNotOptimize(a);
        }
        auto time = t.duration();
        if (time >= 100'000'000){
            std::cout << "B,2HeapMatrix," << n <<",Release,5," << std::round((static_cast<double>(time) / k) * 100.00) / 100.00  << std::endl;
            return 0;
        }
    }
    return -1;
}
int main(){
    stack();
    heap(50);
    heap(100);
    heap(250);
    heap(500);
    heap(1000);
    heap(2000);
    heap2(50);
    heap2(100);
    heap2(250);
    heap2(500);
    heap2(1000);
    heap2(2000);
    return 0;
}