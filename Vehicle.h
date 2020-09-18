#ifndef VEHICLE_H
#define VEHICLE_H

#include <cinttypes>
#include <iostream>

class Vehicle
{


public:
    Vehicle(); //default
    Vehicle(uint16_t numberOfSits, std::string color); //explicit
    Vehicle(const Vehicle& otherVehicle); //copy

    //sobrecarga el operador =
    Vehicle& operator=(const Vehicle& otherVehicle);


    void SetNumberOfSits(uint16_t numberOfSits);
    void SetColor(std::string color);

    uint16_t GetNumberOfSits() const;
    std::string GetColor() const;


private:

    uint16_t NumberOfSits{1};
    std::string Color{"White"};



};

#endif // VEHICLE_H
