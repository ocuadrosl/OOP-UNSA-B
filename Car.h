#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car: public Vehicle
{
public:
    Car();
    Car(uint16_t numberOfSits,
        uint16_t numberOfWheels,
        std::string color);

    std::string GetType(){return "Car\n";}

};

#endif // CAR_H
