#include "matrix/layout.hpp"
#include "matrix/timer.hpp"
#include <iostream>
void print(){
    Naive n1;
    Packed n2;
    std::cout << "Naive: Выравнивание: "<< alignof(Naive)<<std::endl;
    std::cout << "Смещение a: " << offsetof(Naive, a) << " Размер поля " <<sizeof(n1.a)<< " Дыра " << offsetof(Naive, b) - sizeof(n1.a) - offsetof(Naive, a) << std::endl;
    std::cout << "Смещение b: " << offsetof(Naive, b) << " Размер поля " <<sizeof(n1.b)<< " Дыра " << offsetof(Naive, c) - sizeof(n1.b) - offsetof(Naive, b) <<std::endl;
    std::cout << "Смещение c: " << offsetof(Naive, c) << " Размер поля " <<sizeof(n1.c)<< " Дыра " << offsetof(Naive, d) - sizeof(n1.c) - offsetof(Naive, c) <<std::endl;
    std::cout << "Смещение d: " << offsetof(Naive, d) << " Размер поля " <<sizeof(n1.d)<< " Дыра " << offsetof(Naive, e) - sizeof(n1.d) - offsetof(Naive, d) <<std::endl;
    std::cout << "Смещение e: " << offsetof(Naive, e) << " Размер поля " <<sizeof(n1.e)<< " Дыра " << sizeof(Naive) - sizeof(n1.e) - offsetof(Naive, e) <<std::endl;
    std::cout << "Packed: Выравнивание: "<< alignof(Packed)<<std::endl;
    std::cout << "Смещение b: " << offsetof(Packed, b) << " Размер поля " <<sizeof(n2.b)<< " Дыра " << offsetof(Packed, e) - sizeof(n2.b) - offsetof(Packed, b) <<std::endl;
    std::cout << "Смещение e: " << offsetof(Packed, e) << " Размер поля " <<sizeof(n2.e)<< " Дыра " << offsetof(Packed, c) - sizeof(n2.e) - offsetof(Packed, e) << std::endl;
    std::cout << "Смещение c: " << offsetof(Packed, c) << " Размер поля " <<sizeof(n2.c)<< " Дыра " << offsetof(Packed, d) - sizeof(n2.c) - offsetof(Packed, c) << std::endl;
    std::cout << "Смещение d: " << offsetof(Packed, d) << " Размер поля " <<sizeof(n2.d)<< " Дыра " << offsetof(Packed, a) - sizeof(n2.d) - offsetof(Packed, d) << std::endl;
    std::cout << "Смещение a: " << offsetof(Packed, a) << " Размер поля " <<sizeof(n2.a)<< " Дыра " << sizeof(Packed) - sizeof(n2.a) - offsetof(Packed, a) << std::endl;
}
void nai(){
    Naive n1;
    n1.b = 1;
    std::vector<Naive> sp(5000000, n1);
    for (int i = 0; i < 10; ++i){
        doNotOptimize(sNaive(sp));
    }
    Timer t;
    for (int i = 0; i < 5; ++i){
        t.reset();
        uint64_t res = sNaive(sp);
        auto time = t.duration();
        doNotOptimize(res);
        std::cout<<"D,Naive,5000000,Release,"<<i+1<<"," << time<<std::endl;
    }
}
void pac(){
    Packed n1;
    n1.b = 1;
    std::vector<Packed> sp(5000000, n1);
    for (int i = 0; i < 10; ++i){
        doNotOptimize(sPacked(sp));
    }
    Timer t;
    for (int i = 0; i < 5; ++i){
        t.reset();
        uint64_t res = sPacked(sp);
        auto time = t.duration();
        doNotOptimize(res);
        std::cout<<"D,Packed,5000000,Release,"<<i+1<<"," << time<<std::endl;
    }
}
void forc(){
    Forced n1;
    n1.b = 1;
    std::vector<Forced> sp(5000000, n1);
    for (int i = 0; i < 10; ++i){
        doNotOptimize(sForced(sp));
    }
    Timer t;
    for (int i = 0; i < 5; ++i){
        t.reset();
        uint64_t res = sForced(sp);
        auto time = t.duration();
        doNotOptimize(res);
        std::cout<<"D,Forced,5000000,Release,"<<i+1<<"," << time<<std::endl;
    }
}
int main(){
    print();
    nai();
    pac();
    forc();
}