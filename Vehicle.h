#ifndef VEHICLE_H
#define VEHICLE_H

#include <cinttypes>
#include <iostream>
#include <memory>

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

    ~Vehicle(){std::cout<<"Destroyed"<<std::endl;} //liberar la memoria del objeto -> stack o de la heap


private:

    uint16_t NumberOfSits{1};
    std::string Color{"White"};


};

#endif // VEHICLE_H
