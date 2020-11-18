#ifndef FACTORIAL_H
#define FACTORIAL_H


unsigned FactorialRegular(unsigned value)
{
    if(value==0)
    {
        return 1;
    }
    return value * FactorialRegular(value-1);
}


template <unsigned value>
class Factorial
{
public:
    enum {Result = value * Factorial<value-1>::Result};
};

template <>
class Factorial<0>
{
public:
    enum {Result = 1};
};






#endif // FACTORIAL_H
