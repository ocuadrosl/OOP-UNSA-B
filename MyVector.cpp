#include "MyVector.h"
namespace oopb
{
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

bool operator==(const MyVector& a, const MyVector& b)
{
    for(unsigned i=0; i < b.Data.size(); ++i)
    {
        if(a.Data[i] != b.Data[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const MyVector& a, const MyVector& b)
{
   return !(a==b);
}

bool operator < (const MyVector& a, const MyVector& b)
{
    return  std::accumulate(a.Data.begin(), a.Data.end(), 0) <
            std::accumulate(b.Data.begin(), b.Data.end(), 0);
}

bool operator > (const MyVector& a, const MyVector& b)
{
    return b < a;
    //return !(a<b);
    //return !(a<b) || (a==b);
}

bool operator <= (const MyVector& a, const MyVector& b)
{
    return !(a>b);
    //return a==b || a<b; //royer
    //return a < b && a==b; //alexander
    //return a==b || a < b; //kelvin
    //return a == b || a < b; //emilio
}

bool operator >= (const MyVector& a, const MyVector& b)
{
    return !(a<b);
    //return !(b>a); //stephany
    //return a==b || a>b; //melany

}

};






