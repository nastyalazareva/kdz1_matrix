#pragma once
#include <array>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include "config.hpp"
class StackMatrix{
    std::array<Elem, kStackN * kStackN> data_;
public:
    StackMatrix();
    explicit StackMatrix(Elem fill);
    
    Elem at(std::size_t r, std::size_t c) const;
    Elem& at(std::size_t r, std::size_t c);

    static constexpr std::size_t size() {return kStackN; }
    static constexpr std::size_t bytes() { return kStackN * kStackN * sizeof(Elem); }

    static StackMatrix addRef(const StackMatrix& a, const StackMatrix& b);
    static StackMatrix mulRef(const StackMatrix& a, const StackMatrix& b);

    static StackMatrix addVal(StackMatrix a, StackMatrix b);
    static StackMatrix mulVal(StackMatrix a, StackMatrix b);
    static StackMatrix sumAll(const std::vector<StackMatrix>& ms);
}