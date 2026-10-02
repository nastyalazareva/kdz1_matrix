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
    if((*a).size() != (*b).size()){
        throw std::invalid_argument("Invalid argument (different sizes of matrices)");
    }
    HeapMatrix* res = new HeapMatrix((*a).size());
    for (std::size_t i = 0; i < (*a).size(); i++){
        for (std::size_t j = 0; j < (*b).size(); j++){
            (*res).at(i, j) = (*a).at(i, j) + (*b).at(i, j);
        }
    }
    return res;
}

HeapMatrix* HeapMatrix::mulPtr(const HeapMatrix* a, const HeapMatrix* b){
    if((*a).size() != (*b).size()){
        throw std::invalid_argument("Invalid argument (different sizes of matrix)");
    }
    HeapMatrix* res = new HeapMatrix((*a).size(), 0);
    for (std::size_t i = 0; i < (*a).size(); i++){
        for (std::size_t j = 0; j < (*a).size(); j++){
            for (std::size_t i1 = 0; i1 < (*a).size(); i1++){
                (*res).at(i, j) += (*a).at(i, i1) * (*b).at(i1, j);
            }
        }
    }
    return res;
}

HeapMatrix* HeapMatrix::sumAll(const std::vector<const HeapMatrix*>& ms){
    std::size_t s = (*ms[0]).size();
    HeapMatrix* res = new HeapMatrix(s, 0);
    for (auto m: ms){
        if((*m).size() != s){
            delete res;
            throw std::invalid_argument("Invalid argument (different sizes of matrices)");
        }
        HeapMatrix* nr = addPtr(res, m);
        delete res;
        res = nr;
    }
    return res;
}