#ifndef ADAPTER_H
#define ADAPTER_H

#include <memory>
#include <iostream>
#include <cmath>

class GeometricShape
{

public:
    virtual double Volume() const =0;
};



class Sphere
{
    std::string Name{"Sphere"};

public:
    double GetVolume(double radius)
    {
       return (4/3)  * 3.1415 * std::pow(radius,3);
    };

    void SetMessage(const std::string & name){Name = name;}
    std::string GetName()const{return Name;}


};


class SphereAdapter: public GeometricShape
{

private:

    Sphere& sphere;
    double Radius{};

public:
    SphereAdapter(Sphere& sphere): sphere{sphere}
    {}
    double Volume() const override
    {
        sphere.SetMessage("Adapted Sphere");
        return sphere.GetVolume(Radius);
    }
    void SetRadius(double radius){Radius=radius;}

};







#endif // ADAPTER_H
