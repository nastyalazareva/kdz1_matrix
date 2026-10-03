#include "matrix/timer.hpp"
#include <iostream>
#include "matrix/stack_matrix.hpp"
#include "matrix/heap_matrix.hpp"
void crashtest(){
    HeapMatrix a(10, 1);
    HeapMatrix b = a; 
}
void ref(){
    StackMatrix a(2), b(4);
    for (int i = 0; i < 3; ++i){
        doNotOptimize(StackMatrix::mulRef(a, b));
    }
    Timer t1;
    auto time = t1.duration();
    for (int i = 0; i < 5; ++i){
        t1.reset();
        doNotOptimize(StackMatrix::mulRef(a, b));
        time = t1.duration();
        std::cout <<"A,Stack mulRef,500,Release,"<<i + 1 << "," << time << std::endl;
    }
}

void val(){
    StackMatrix a(2), b(4);
    for (int i = 0; i < 3; ++i){
        doNotOptimize(StackMatrix::mulVal(a, b));
    }
    Timer t1;
    auto time = t1.duration();
    for (int i = 0; i < 5; ++i){
        t1.reset();
        doNotOptimize(StackMatrix::mulVal(a, b));
        time = t1.duration();
        std::cout <<"A,Stack mulVal,500,Release," << i + 1 << ","<< time << std::endl;
    }
}

void lim1(){
    StackMatrix c(2);
}
void lim3(){
    StackMatrix a(2), b(4);
    doNotOptimize(StackMatrix::mulRef(a, b));
}
void lim5(){
    StackMatrix a(2), b(4);
    doNotOptimize(StackMatrix::mulVal(a, b));
}
void matr_1000(){
    StackMatrix a(2);
    a.at(6, 7) = 67;
    doNotOptimize(a);
    std::cout << sizeof(a);
}
void heap(){
    for (int i = 0; i < 3; ++i){
        HeapMatrix a(1000, 2);
        doNotOptimize(a);
    }
    for (int i = 0; i < 5; ++i){
        Timer t;
        HeapMatrix a(1000, 2);
        doNotOptimize(a);
        auto time = t.duration();
        std::cout << "A,HeapMatrix,1000,Release," << i + 1 << ","<< time << std::endl;
    }
}
int main(){
    crashtest();
    // ref();
    // val();
    // lim1();
    // lim3();
    // lim5();
    // matr_1000();
    // heap();
}