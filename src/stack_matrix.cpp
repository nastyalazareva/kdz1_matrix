#include "matrix/stack_matrix.hpp"
StackMatrix::StackMatrix(){
    data_.fill(0);
}
StackMatrix::StackMatrix(Elem fill){
    data_.fill(fill);
}
Elem StackMatrix::at(std::size_t r, std::size_t c) const{
    if (r >= kStackN or c >= kStackN){
        throw std::out_of_range("Index out of range");
    }
    else {
        return data_[kStackN * r + c];
    }
}
Elem& StackMatrix::at(std::size_t r, std::size_t c){
    if (r >= kStackN or c >= kStackN){
        throw std::out_of_range("Index out of range");
    }
    else {
        return data_[kStackN * r + c];
    }
}
StackMatrix StackMatrix::addRef(const StackMatrix& a, const StackMatrix& b){
    StackMatrix c;
    for (std::size_t i = 0; i < kStackN; i++){
        for (std::size_t j = 0; j < kStackN; j++){
            c.at(i, j) = a.at(i, j) + b.at(i, j);
        }
    }
    return c;
}
StackMatrix StackMatrix::mulRef(const StackMatrix& a, const StackMatrix& b){
    StackMatrix c;
    for (std::size_t i = 0; i < kStackN; i++){
        for (std::size_t j = 0; j < kStackN; j++){
            for (std::size_t i1 = 0; i1 < kStackN; i1++){
                c.at(i, j) += a.at(i, i1) * b.at(i1, j);
            }
        }
    }
    return c;
}
StackMatrix StackMatrix::addVal(StackMatrix a, StackMatrix b){
    StackMatrix c;
    for (std::size_t i = 0; i < kStackN; i++){
        for (std::size_t j = 0; j < kStackN; j++){
            c.at(i, j) = a.at(i, j) + b.at(i, j);
        }
    }
    return c;
}
StackMatrix StackMatrix::mulVal(StackMatrix a, StackMatrix b){
    StackMatrix c;
    for (std::size_t i = 0; i < kStackN; i++){
        for (std::size_t j = 0; j < kStackN; j++){
            for (std::size_t i1 = 0; i1 < kStackN; i1++){
                c.at(i, j) += a.at(i, i1) * b.at(i1, j);
            }
        }
    }
    return c;
}
StackMatrix StackMatrix::sumAll(const std::vector<StackMatrix>& ms){
    StackMatrix c;
    for (auto m: ms){
        c = addRef(c, m);
    }
    return c;
}