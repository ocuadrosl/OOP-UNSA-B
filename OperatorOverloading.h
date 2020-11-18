#ifndef OPERATOROVERLOADING_H
#define OPERATOROVERLOADING_H

#include <vector>

class Vector
{
    std::vector<int> Data{};

public:
    Vector()=delete;
    Vector(const std::size_t& size, const int& value=0): Data{std::vector<int>(size, value)}{}

    const int& operator[] (unsigned index) const {return Data[index];}
    int& operator[](unsigned index) {return Data[index];}

};

class Matrix
{
    std::vector< Vector > Data{};

public:
    Matrix()=delete;
    Matrix(const std::size_t& row, const std::size_t& cols, const int& value=0) : Data{std::vector<Vector>(row, {cols, value})}{}

    const Vector& operator[] (unsigned index) const {return Data[index];}
    Vector& operator[] (unsigned index){return Data[index];}

};









#endif // OPERATOROVERLOADING_H
