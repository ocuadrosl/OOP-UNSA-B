#include <iostream> //global files
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

    //Todo objeto tiene un direccion en la heap de tamno 8-bits
    Vehicle moto;
    print(moto);

    Vehicle car1{4, "Blue"};
    Vehicle car2;
    //print(car2); //copiando, en caso de no ser referencia

    car2 = car1; //igualando

    print(car2);

    return 0;
}

