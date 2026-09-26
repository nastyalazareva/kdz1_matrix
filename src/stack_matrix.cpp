#include "stack_matrix.hpp"
class StackMatrix{
    std::array<Elem, kStackN * kStackN> data_;
public:
    StackMatrix(){
        data_.fill(0);
    }
    explicit StackMatrix(Elem fill){
        data_.fill(fill);
    }
    Elem at(std::size_t r, std::size_t c) const{
        if (r >= kStackN or c >= kStackN){
            throw std::out_of_range("Index out of range");
        }
        else {
            return data_[kStackN * r + c];
        }
    }
    Elem& at(std::size_t r, std::size_t c){
        if (r >= kStackN or c >= kStackN){
            throw std::out_of_range("Index out of range");
        }
        else {
            return data_[kStackN * r + c];
        }
    }
    static constexpr std::size_t size(){
        return kStackN;
    }
    static constexpr std::size_t bytes(){
        return kStackN * kStackN * sizeof(Elem);
    }
    static StackMatrix addRef(const StackMatrix& a, const StackMatrix& b){
        StackMatrix c;
        for (std::size_t i = 0; i < kStackN; i++){
            for (std::size_t j = 0; j < kStackN; j++){
                c.at(i, j) = a.at(i, j) + b.at(i, j);
            }
        }
        return c;
    }
    static StackMatrix mulRef(const StackMatrix& a, const StackMatrix& b){
        StackMatrix c;
        for (int i = 0; i < kStackN; i++){
            for (int j = 0; j < kStackN; j++){
                for (int i1 = 0; i1 < kStackN; i1++){
                    c.at(i, j) += a.at(i, i1) * b.at(j, i1);
                }
            }
        }
        return c;
    }
    static StackMatrix addVal(StackMatrix a, StackMatrix b){
        StackMatrix c;
        for (int i = 0; i < kStackN; i++){
            for (int j = 0; j < kStackN; j++){
                for (int i1 = 0; i1 < kStackN; i1++){
                    c.at(i, j) += a.at(i, i1) * b.at(j, i1);
                }
            }
        }
        return c;
    }
    static StackMatrix mulRef(const StackMatrix& a, const StackMatrix& b){
        StackMatrix c;
        for (int i = 0; i < kStackN; i++){
            for (int j = 0; j < kStackN; j++){
                for (int i1 = 0; i1 < kStackN; i1++){
                    c.at(i, j) += a.at(i, i1) * b.at(j, i1);
                }
            }
        }
        return c;
    }
    static StackMatrix sumAll(const std::vector<StackMatrix>& ms){
        StackMatrix c;
        for (auto m: ms){
            c = addRef(c, m);
        }
        return c;
    }
};