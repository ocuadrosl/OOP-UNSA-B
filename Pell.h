#ifndef PELL_H
#define PELL_H


template <unsigned value>
struct Pell
{
    enum { Result = 2*Pell<value-1>::Result + Pell<value-2>::Result};
};

template <>
struct Pell<0>
{
    enum { Result = 0};
};

template <>
struct Pell<1>
{
    enum { Result = 1};
};










#endif // PELL_H
