#ifndef VEHICLE_H
#define VEHICLE_H

#include <cinttypes>
#include <iostream>
#include <memory>

class Vehicle
{


public:
    Vehicle(); //default

    Vehicle(uint16_t numberOfSits,
            uint16_t numberOfWheels,
            std::string color); //explicit

    Vehicle(const Vehicle& otherVehicle); //copy -> lvalue
    Vehicle(Vehicle&& otherVehicle);//rvalue

    //sobrecarga el operador =
    Vehicle& operator=(const Vehicle& otherVehicle);


    void SetNumberOfSits(uint16_t numberOfSits);
    void SetColor(std::string color);

    uint16_t GetNumberOfSits() const;
    uint16_t GetNumberOfWheels() const;
    std::string GetColor() const;

    ~Vehicle(){std::cout<<"Destroyed"<<std::endl;} //liberar la memoria del objeto -> stack o de la heap


    protected:

    uint16_t NumberOfSits{1};
    uint16_t NumberOfWheels{1};
    std::string Color{"White"};




};

#endif // VEHICLE_H
