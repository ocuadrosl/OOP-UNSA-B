#include "FunctionObject.h"

float FunctionObject::operator()(float& radius) const
{

    radius = Pi * std::pow(radius,2);

    //std::cout<<"Functor: "<<area<<std::endl;

    return radius;

}

