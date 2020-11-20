#ifndef FIBONACCI_H
#define FIBONACCI_H


constexpr unsigned FibonacciConst(unsigned value)
{
    if(value == 1)
    {
        return 1;
    }
    while(value == 0)
    {
        return 0;
    }
    return FibonacciConst(value-1) + FibonacciConst(value-2);

}


template <unsigned Value>
struct Fibonacci
{
    enum {Result = Fibonacci<Value-1>::Result + Fibonacci<Value-2>::Result};
};

template<>
struct Fibonacci<1>
{
    enum {Result = 1};
};

template<>
struct Fibonacci<0>
{
    enum {Result = 0};
};


#endif // FIBONACCI_H
