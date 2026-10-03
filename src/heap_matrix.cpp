#include "matrix/heap_matrix.hpp"
HeapMatrix::HeapMatrix(std::size_t n): n_(n){
    if (n_ == 0){
        throw std::invalid_argument("Invalid argument (n = 0)");
    }
    data_ = new Elem[n*n];
}
HeapMatrix::HeapMatrix(std::size_t n, Elem fill)
: n_(n),
data_(nullptr) {
    if (n_ == 0){
        throw std::invalid_argument("Invalid argument (n = 0)");
    }
    data_ = new Elem[n*n];
    for (std::size_t i=0; i < n_*n_; i++){
        data_[i] = fill;
    }
}

HeapMatrix::~HeapMatrix(){
    delete[] data_;
}

Elem HeapMatrix::at(std::size_t r, std::size_t c) const{
    if (r >= n_ or c >= n_){
        throw std::out_of_range("Out of range (r >= n or c >= n)");
    }
    return data_[r * n_ + c];
}
Elem& HeapMatrix::at(std::size_t r, std::size_t c){
    if (r >= n_ or c >= n_){
        throw std::out_of_range("Out of range (r >= n or c >= n)");
    }
    return data_[r * n_ + c];
}

HeapMatrix* HeapMatrix::addPtr(const HeapMatrix* a, const HeapMatrix* b){
    if((*a).n_ != (*b).n_){
        throw std::invalid_argument("Invalid argument (different sizes of matrices)");
    }
    std::size_t s = (*a).n_;
    HeapMatrix* res = new HeapMatrix(s, 0);
    for (std::size_t i = 0; i < s * s; i++) {
        (*res).data_[i] = (*a).data_[i] + (*b).data_[i];
    }
    return res;
}

HeapMatrix* HeapMatrix::mulPtr(const HeapMatrix* a, const HeapMatrix* b){
    if((*a).n_ != (*b).n_){
        throw std::invalid_argument("Invalid argument (different sizes of matrix)");
    }
    std::size_t s = (*a).n_;
    HeapMatrix* res = new HeapMatrix(s, 0);
    for (std::size_t i = 0; i < s; i++){
        for (std::size_t j = 0; j < s; j++){
            for (std::size_t i1 = 0; i1 < s; i1++){
                (*res).data_[i * s + j] += (*a).data_[i * s + i1] * (*b).data_[i1 * s + j];
            }
        }
    }
    return res;
}

HeapMatrix* HeapMatrix::sumAll(const std::vector<const HeapMatrix*>& ms){
    std::size_t s = (*ms[0]).n_;
    HeapMatrix* res = new HeapMatrix(s, 0);
    for (auto m: ms){
        if((*m).n_ != s){
            delete res;
            throw std::invalid_argument("Invalid argument (different sizes of matrices)");
        }
    }
    for (std::size_t i = 0; i < s * s; i++) {
        for (std::size_t j = 0; j < ms.size(); j++) {
            (*res).data_[i] += (*ms[j]).data_[i];
        }
    }
    return res;
}