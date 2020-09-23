#include <iostream> //global files
#include <memory>
#include "Vehicle.h" //local files

/*
Por defecto c++ pasa argumentos por valor -> hace una copia
&->referencia (alias), pasar la direccion
*/
void print(const Vehicle& vehicle) //& solo en la funcion
{

    std::cout << vehicle.GetNumberOfSits() << std::endl;
    std::cout << vehicle.GetColor() << std::endl;
    return;
}


int main()
{

    auto carSmartPtr = std::make_unique<Vehicle>(1, "Blue"); //usar ESTA FORMA

    std::cout<<carSmartPtr->GetColor()<<std::endl;
    Vehicle car = *carSmartPtr;
    print(*carSmartPtr);


 /*   //Todo objeto tiene un direccion en la heap de tamno 8-bits
    Vehicle moto; //stack

    //NO usar Raw Pointers!!!
    {
        Vehicle** motoPtr = new Vehicle*;
        *motoPtr = new Vehicle;
        delete *motoPtr;
        delete  motoPtr;
    }

*/
    //no usar nunca!!!
/*    {
        int *array = new int[10];
        array[0] = 2;
        std::cout<<array[0]<<std::endl;
        delete[] array;
    }

*/
    return 0;
}

