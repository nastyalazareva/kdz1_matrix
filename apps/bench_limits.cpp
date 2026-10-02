#include "matrix/timer.hpp"
#include <iostream>
#include "matrix/stack_matrix.hpp"
#include "matrix/heap_matrix.hpp"
void ref(){
    StackMatrix a(2), b(4);
    for (int i = 0; i < 3; ++i){
        doNotOptimize(StackMatrix::mulRef(a, b));
    }
    Timer t1;
    for (int i = 0; i < 5; ++i){
        t1.reset();
        doNotOptimize(StackMatrix::mulRef(a, b));
        std::cout <<"A,Stack mulRef,500,Release,"<<i + 1 << "," <<  t1.duration() << std::endl;
    }
}

void val(){
    StackMatrix a(2), b(4);
    for (int i = 0; i < 3; ++i){
        doNotOptimize(StackMatrix::mulVal(a, b));
    }
    Timer t1;
    for (int i = 0; i < 5; ++i){
        t1.reset();
        doNotOptimize(StackMatrix::mulVal(a, b));
        std::cout <<"A,Stack mulVal,500,Release," << i + 1 << ","<<  t1.duration() << std::endl;
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
    std::cout << sizeof(a);
}
void heap(){
    Timer t;
    HeapMatrix a(4000, 2);
    std::cout << "A,HeapMatrix,4000,Debug,1," << t.duration();
}
int main(){
    ref();
    val();
    //lim1();
    // lim3();
    //lim5();
    // matr_1000();
    // heap();
}