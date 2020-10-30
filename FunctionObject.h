#ifndef FUNCTIONOBJECT_H
#define FUNCTIONOBJECT_H

#include <cmath>
#include <iostream>

class FunctionObject //Functor
{
private:

    const float Pi{3.1415f};

public:

   float  operator()(float& radius) const; //operator() -> nombre

   void PrintPi() const {std::cout<<Pi<<std::endl;};


};

#endif // FUNCTIONOBJECT_H
