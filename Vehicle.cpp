#include "Vehicle.h"

Vehicle::Vehicle()
{

    std::cout<<"Default"<<std::endl;
}

Vehicle::Vehicle(uint16_t numberOfSits, std::string color):
    NumberOfSits{numberOfSits},
    Color{color}
{
    std::cout<<"Explicit"<<std::endl;

}

Vehicle::Vehicle(const Vehicle& otherVehicle):
    NumberOfSits{otherVehicle.NumberOfSits},
    Color{otherVehicle.Color}
{
    std::cout<<"Copy"<<std::endl;
}


void Vehicle::SetNumberOfSits(uint16_t numberOfSits)
{

    this->NumberOfSits =  numberOfSits;

}
void Vehicle::SetColor(std::string color)
{

    this->Color = color;
}

u_int16_t Vehicle::GetNumberOfSits() const
{
    return NumberOfSits;
}
std::string Vehicle::GetColor() const
{
    return Color;
}

Vehicle& Vehicle::operator=(const Vehicle& otherVehicle)
{
    std::cout<<"equal"<<std::endl;
}




