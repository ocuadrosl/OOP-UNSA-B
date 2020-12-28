#ifndef GEOMETRICSHAPE_H
#define GEOMETRICSHAPE_H

#include <cmath>
#include <iostream>

class GeometricShape //Client
{

public:
    virtual double Volume() const = 0;

};


class Cube : public GeometricShape
{
public:
    double Volume() const override { return -1; };

};


class Sphere //Adaptee
{


    std::string Name{"Sphere"};

public:
    double GetVolume(double radius) const
    {
        return (4/3)*3.1415*std::pow(radius,3);
    };

    void SetName(const std::string & name)
    {
        Name = name;
    }
    std::string GetName() const {return Name;}

};


class SphereAdapter : public GeometricShape //adapter
{

    Sphere& sphere;
    double Radius{};
public:
    SphereAdapter(Sphere& sphere): sphere{sphere}
    {}
    double Volume() const override
    {
        sphere.SetName("Adapted Sphere");
        return sphere.GetVolume(Radius);
    }

    void SetRadius(double radius){Radius = radius;}



};





#endif // GEOMETRICSHAPE_H
