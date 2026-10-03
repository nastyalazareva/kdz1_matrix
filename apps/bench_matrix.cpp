#include "matrix/timer.hpp"
#include <iostream>
#include "matrix/stack_matrix.hpp"
#include "matrix/heap_matrix.hpp"
#include<vector>
void aRef(){
    StackMatrix a(2), b(4);
    for (int i = 0; i < 50; ++i){
        doNotOptimize(StackMatrix::addRef(a, b));
    }
    Timer t;
    for(int i = 0; i < 5; ++i){
        t.reset();
        StackMatrix c = StackMatrix::addRef(a, b);
        auto time = t.duration();
        doNotOptimize(c);
        std::cout << "C,addRef,500,Release," << i + 1 << "," << time << std::endl;
    }
}
void aVal(){
    StackMatrix a(2), b(4);
    for (int i = 0; i < 50; ++i){
        doNotOptimize(StackMatrix::addVal(a, b));
    }
    Timer t;
    for (int i = 0; i < 5; ++i){
        t.reset();
        StackMatrix c = StackMatrix::addVal(a, b);
        auto time = t.duration();
        doNotOptimize(c);
        std::cout << "C,addVal,500,Release," << i + 1 << "," << time << std::endl;
    }
}
void mRef(){
    StackMatrix a(2), b(4);
    for (int i = 0; i < 10; ++i){
        doNotOptimize(StackMatrix::mulRef(a, b));
    }
    Timer t;
    for(int i = 0; i < 5; ++i){
        t.reset();
        StackMatrix c = StackMatrix::mulRef(a, b);
        auto time = t.duration();
        doNotOptimize(c);
        std::cout << "C,mulRef,500,Release," << i + 1 << "," << time << std::endl;
    }
}
void mVal(){
    StackMatrix a(2), b(4);
    for (int i = 0; i < 10; ++i){
        doNotOptimize(StackMatrix::mulVal(a, b));
    }
    Timer t;
    for (int i = 0; i < 5; ++i){
        t.reset();
        StackMatrix c = StackMatrix::mulVal(a, b);
        auto time = t.duration();
        doNotOptimize(c);
        std::cout << "C,mulVal,500,Release," << i + 1 << "," << time << std::endl;
    }
}
void sAll_st(){
    std::vector<StackMatrix> sp;
    for (int i = 0; i < 20; ++i){
        StackMatrix a(2);
        sp.push_back(a);
    }
    for (int i = 0; i < 10; ++i){
        doNotOptimize(StackMatrix::sumAll(sp));
    }
    Timer t;
    for (int i = 0; i < 5; ++i){
        t.reset();
        StackMatrix c = StackMatrix::sumAll(sp);
        auto time = t.duration();
        doNotOptimize(c);
        std::cout << "C,sumAll_Stack,500,Release," << i + 1 << "," << time << std::endl;
    }
}

void aPtr(std::size_t n){
    HeapMatrix a(n, 2), b(n, 4);
    for (int i = 0; i < 50; ++i){
        HeapMatrix* d = HeapMatrix::addPtr(&a, &b);
        doNotOptimize(*d);
        delete d;
    }
    Timer t;
    for (int i = 0; i < 5; ++i){
        t.reset();
        HeapMatrix* c = HeapMatrix::addPtr(&a, &b);
        auto time = t.duration();
        doNotOptimize(*c);
        std::cout << "C,addPtr," << n << ",Release," << i + 1 << "," << time << std::endl;
        delete c;
    }
}

void mPtr(std::size_t n){
    HeapMatrix a(n, 2), b(n, 4);
    for (int i = 0; i < 50; ++i){
        HeapMatrix* d = HeapMatrix::mulPtr(&a, &b);
        doNotOptimize(*d);
        delete d;
    }
    Timer t;
    for (int i = 0; i < 5; ++i){
        t.reset();
        HeapMatrix* c = HeapMatrix::mulPtr(&a, &b);
        auto time = t.duration();
        doNotOptimize(*c);
        std::cout << "C,mulPtr," << n << ",Release," << i + 1 << "," << time << std::endl;
        delete c;
    }
}

void sAll_he(std::size_t n){
    std::vector<const HeapMatrix*> sp;
    for (int i =0; i < 20; ++i){;
        sp.push_back(new HeapMatrix(n, 2));
    }
    for (int i = 0; i < 3; ++i){
        HeapMatrix* d = HeapMatrix::sumAll(sp);
        doNotOptimize(*d);
        delete d;
    }
    Timer t;
    for (int i = 0; i < 5; ++i){
        t.reset();
        HeapMatrix* c = HeapMatrix::sumAll(sp);
        auto time = t.duration();
        doNotOptimize(*c);
        std::cout << "C,sumAll_Heap," << n <<",Release," << i + 1 << "," << time << std::endl;
        delete c;
    }
    for (auto el:sp){
        delete el;
    }
}

int main(){
    aPtr(500);
    mPtr(500);
    aPtr(1000);
    aPtr(2000);
    mPtr(1000);
    aRef();
    aVal();
    mRef();
    mVal();
    sAll_st();
    sAll_he(500);
    return 0;
}