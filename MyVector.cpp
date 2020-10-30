#include "MyVector.h"

MyVector::MyVector(const std::size_t& size):
    Data{ std::vector<int>(size, {}) }
{

}

const int& MyVector::operator[] (unsigned index) const
{
    return Data[index];
}

int& MyVector::operator[](unsigned index)
{
    return Data[index];
}


MyVector operator+(const MyVector& a, const MyVector& b)
{
    MyVector result{a.Data.size()};

    for(unsigned i=0; i< result.Data.size(); ++i)
    {
        result[i] = a[i] + b[i];
    }

   return result;
}

MyVector operator+(const MyVector& a, int nro)
{
    MyVector result{a.Data.size()};

    for(unsigned i=0; i< result.Data.size(); ++i)
    {
        result[i] = a[i] + nro;
    }

   return result;
}

MyVector operator+(int nro, const MyVector& a)
{
    /*MyVector result{a.Data.size()};

    for(unsigned i=0; i< result.Data.size(); ++i)
    {
        result[i] = a[i] + nro;
    }
    */

   return a + nro;
}

std::ostream& operator<< (std::ostream& output,  const MyVector& v)
{

    output<<"[";

    for(auto it = v.Data.begin(); it != v.Data.end()-1; ++it)
    {
        output<<*it<<",";
    }

    output<<*v.Data.rbegin()<<"]";

    return output;
}











