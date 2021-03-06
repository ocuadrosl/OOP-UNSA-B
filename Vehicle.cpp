#include "Vehicle.h"

Vehicle::Vehicle()
{

    std::cout<<"Vehicle Default"<<std::endl;
}

Vehicle::Vehicle(uint16_t numberOfSits,
                 uint16_t numberOfWheels,
                 std::string color):
    NumberOfSits{numberOfSits},
    NumberOfWheels{numberOfWheels},
    Color{color}
{
    std::cout<<" Vehicle Explicit"<<std::endl;

}

Vehicle::Vehicle(const Vehicle& otherVehicle):
    NumberOfSits{otherVehicle.NumberOfSits},
    Color{otherVehicle.Color}
{
    std::cout<<"Copy"<<std::endl;
}


Vehicle::Vehicle(Vehicle&& otherVehicle):
    NumberOfSits{otherVehicle.NumberOfSits},
    Color{otherVehicle.Color}
{
    std::cout<<"Move"<<std::endl;
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

uint16_t Vehicle::GetNumberOfWheels() const
{
    return NumberOfWheels;
}

Vehicle& Vehicle::operator=(const Vehicle& otherVehicle)
{
    std::cout<<"equal"<<std::endl;
}




