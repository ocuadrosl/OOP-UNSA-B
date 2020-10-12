#include <iostream> //global files
#include <memory>
#include "Vehicle.h" //local files
#include "Car.h"
#include <vector>
#include "Queen.h"
#include "Pawn.h"


/*
Por defecto c++ pasa argumentos por valor -> hace una copia
&->referencia (alias), pasar la direccion
*/
void print(const Vehicle& vehicle) //& solo en la funcion
{
    std::cout << vehicle.GetNumberOfSits()   << std::endl;
    std::cout << vehicle.GetNumberOfWheels() << std::endl;
    std::cout << vehicle.GetColor() << std::endl;
    return;
}

void notMyPrint(Vehicle vehicle) //& solo en la funcion
{
    std::cout << vehicle.GetNumberOfSits() << std::endl;
    std::cout << vehicle.GetColor() << std::endl;
    return;
}


int foo(int& x)
{
    std::cout<<"lvalue"<<std::endl;
    return ++x;
}

void foo(int&& x)
{
    //std::cout<<"rvalue"<<std::endl;
    x-=-1;
}




int main()
{

  /*  using PiecePtr = std::shared_ptr<Piece>;

    PiecePtr pawn1 = std::make_shared<Pawn>("White");
    PiecePtr pawn2 = std::make_unique<Pawn>("White");
    PiecePtr pawn3 = std::make_unique<Pawn>("White");
    PiecePtr pawn4 = std::make_unique<Pawn>("White");
    PiecePtr pawn5 = std::make_unique<Pawn>("White");
    PiecePtr pawn6 = std::make_unique<Pawn>("White");

    pawn2 = std::make_shared<Queen>("");

    std::cout<<pawn6->GetID()<<std::endl;
*/







    //no puedo crear objetos de la clase base-> polimorfismo
    //Piece piece;


    //verbosity








    return 0;
}

