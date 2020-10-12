#include "Car.h"

Car::Car() : Vehicle( 2, 4, "Blue" ) //modificando
{
    std::cout<<"Car Default\n";
}


Car::Car(uint16_t numberOfSits,
    uint16_t numberOfWheels,
    std::string color)
{
    NumberOfSits = numberOfSits;
    NumberOfWheels = numberOfWheels;
    Color = color;
    std::cout<<"Car Explict\n";
}

