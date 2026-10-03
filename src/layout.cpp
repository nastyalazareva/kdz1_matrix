#include "matrix/layout.hpp"
#include <vector>
std::uint64_t sNaive(std::vector<Naive>& sp){
    std::uint64_t s = 0;
    for (Naive& el: sp){
        s += el.b;
    }
    return s;
}
std::uint64_t sPacked(std::vector<Packed>& sp){
    std::uint64_t s = 0;
    for (Packed& el: sp){
        s += el.b;
    }
    return s;
}
std::uint64_t sForced(std::vector<Forced>& sp){
    std::uint64_t s = 0;
    for (Forced& el: sp){
        s += el.b;
    }
    return s;
}