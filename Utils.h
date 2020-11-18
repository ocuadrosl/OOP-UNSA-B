#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <cmath>

#include "MyVector.h"

namespace utils
{

//compilacion
template <typename Type>
void sum(Type a, Type b)
{
    std::cout<<a + b<<"\n";
}


template <typename VectorTypeA, typename VectorTypeB, unsigned size>
double EuclideanDistance(const VectorTypeA& a, const VectorTypeB& b)
{

    double  diffs = 0;
    for(unsigned i=0; i < size ; ++i)
    {
        diffs += std::pow(a[i] - b[i], 2);
    }
    return std::sqrt(diffs);

}



}


#endif // UTILS_H
