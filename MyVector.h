#ifndef MYVECTOR_H
#define MYVECTOR_H

#include<vector>
#include <iostream>
#include <numeric>

namespace oopb
{

class MyVector
{

std::vector<int> Data{0};

public:

    MyVector()=delete;
    MyVector(const std::size_t& size);

    const int& operator[] (unsigned index) const;
    int& operator[] (unsigned index);

    int& At(unsigned index) {return Data[index];}

    friend MyVector operator+(const MyVector& a, const MyVector& b);
    friend MyVector operator+(const MyVector& a, int nro);
    friend MyVector operator+(int nro, const MyVector& a);
    friend std::ostream& operator<< (std::ostream& output,  const MyVector& v);

    friend bool operator==(const MyVector& a, const MyVector& b);
    friend bool operator!=(const MyVector& a, const MyVector& b);
    friend bool operator< (const MyVector& a, const MyVector& b);
    friend bool operator> (const MyVector& a, const MyVector& b);
    friend bool operator<=(const MyVector& a, const MyVector& b);
    friend bool operator>=(const MyVector& a, const MyVector& b);

};

};
#endif // MYVECTOR_H
