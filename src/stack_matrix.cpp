#include "matrix/stack_matrix.hpp"
StackMatrix::StackMatrix(){
    data_.fill(0);
}
StackMatrix::StackMatrix(Elem fill){
    data_.fill(fill);
}
Elem StackMatrix::at(std::size_t r, std::size_t c) const{
    if (r >= kStackN or c >= kStackN){
        throw std::out_of_range("Index out of range (r >= kstackN or c >= kStackN)");
    }
    else {
        return data_[kStackN * r + c];
    }
}
Elem& StackMatrix::at(std::size_t r, std::size_t c){
    if (r >= kStackN or c >= kStackN){
        throw std::out_of_range("Index out of range(r >= kstackN or c >= kStackN)");
    }
    else {
        return data_[kStackN * r + c];
    }
}
StackMatrix StackMatrix::addRef(const StackMatrix& a, const StackMatrix& b){
    StackMatrix c;
    for (std::size_t i = 0; i < kStackN * kStackN; i++){
        c.data_[i] = a.data_[i] + b.data_[i];
    }
    return c;
}
StackMatrix StackMatrix::mulRef(const StackMatrix& a, const StackMatrix& b){
    StackMatrix c;
    for (std::size_t i = 0; i < kStackN; i++){
        for (std::size_t j = 0; j < kStackN; j++){
            for (std::size_t i1 = 0; i1 < kStackN; i1++){
                c.data_[i * kStackN + j] += a.data_[i * kStackN + i1] * b.data_[i1 * kStackN + j];
            }
        }
    }
    return c;
}
StackMatrix StackMatrix::addVal(StackMatrix a, StackMatrix b){
    return addRef(a, b);
}
StackMatrix StackMatrix::mulVal(StackMatrix a, StackMatrix b){
    return mulRef(a, b);
}
StackMatrix StackMatrix::sumAll(const std::vector<StackMatrix>& ms){
    StackMatrix c;
    for (std::size_t i = 0; i < kStackN * kStackN; i++) {
        for (std::size_t j = 0; j < ms.size(); j++) {
            c.data_[i] += ms[j].data_[i];
        }
    }
    return c;
}