#ifndef MYVECTOR_H
#define MYVECTOR_H

#include<vector>
#include <iostream>

class MyVector
{

    std::vector<int> Data{0};

public:
    MyVector(){}
    MyVector(const std::size_t& size);

    const int& operator[] (unsigned index) const;
    int& operator[] (unsigned index);

    //int& At(unsigned index){return Data[index];}

    friend MyVector operator+(const MyVector& a, const MyVector& b);
    friend MyVector operator+(const MyVector& a, int nro);
    friend MyVector operator+(int nro, const MyVector& a);


    friend std::ostream& operator<< (std::ostream& output,  const MyVector& v);



};

#endif // MYVECTOR_H
