#include <iostream> //global files
#include <memory>
#include "Vehicle.h" //local files
#include "Car.h"
#include <vector>
#include "Queen.h"
#include "Pawn.h"
#include "FunctionObject.h"
#include "MyVector.h"

#include <functional>


/*
Por defecto c++ pasa argumentos por valor -> hace una cFunctionObject::FunctionObject()
{

}
opia
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



int foo(int&& x)
{
    return x +- 1;
}


class Player
{

protected:
    std::string Team{};
    uint16_t Number{};
public:
    Player() = delete; //herencia
    explicit Player(const std::string & team): Team{team} { Number = Player::Counter++;}
    virtual void Play() = 0;
    uint16_t GetNumber(){ return Number;}
    virtual ~Player(){}
    static uint16_t Counter;

};

uint16_t Player::Counter{1};

class RegularPlayer: public Player
{

public:
    RegularPlayer() = delete; //herencia
    explicit RegularPlayer(const std::string & team): Player{team} {}
    void Play() override {std::cout<<"Plays with foot\n";}
    ~RegularPlayer(){}
};


class GoalKeeper: public Player
{

public:
    GoalKeeper() = delete; //herencia
    explicit GoalKeeper(const std::string & team): Player{team} {}
    void Play() override {std::cout<<"Plays with hand\n";}
    ~GoalKeeper(){}
};


//regular function
float AreaCircle(float &val)
{
    val = 3.14f * std::pow(val,2);
    return val;
    //std::cout<<"Function: "<<area<<std::endl;
}


void TestV1()
{

   FunctionObject areaCircle;
   std::vector<float> radius(10);

   for(auto& r: radius)
   {
       r = std::rand()%100;
      // std::cout<<r<<"\n";
   }
   std::vector<float> areasFO(10);

   std::vector<float>::iterator a = areasFO.begin();
   auto r = radius.begin();

   for(; a != areasFO.end(); ++a, ++r)
   {
       *a = areaCircle(*r);
   }

   std::vector<float> areasFun(10);
   a = areasFun.begin();
   r = radius.begin();
   for(; a!= areasFun.end(); ++a, ++r)
   {
       *a = AreaCircle(*r);
   }


}



void TestV2(const std::function<float(float&)>& areaFunc, unsigned size)
{

    std::vector<float> radius(size);

    int limit=100;
    std::for_each(radius.begin(), radius.end(), [limit](float &r){r = std::rand()%limit;} );

    std::for_each(radius.begin(), radius.end(), areaFunc);

    for(auto a: radius)
    {
        std::cout<<a<<"\n";
    }

}
void var(const oopb::MyVector& a)
{

    std::cout << a[2] <<"\n";
}


int main()
{

    oopb::MyVector a{10}, b{10};

    a[1] = 10;
    b[1] = 9;


    a.At(1) = 9;


    std::cout << a[2] <<"\n";
    std::cout << b <<"\n";

    std::cout << (b >= a)<<std::endl;


   /* std::function<float(float&)> areaCFun = AreaCircle;
    std::function<float(float&)> areaCFO  = FunctionObject();


    TestV2(areaCFun, 10);
    TestV2(areaCFO, 10);
   */




/*
    [](){};
    int x=10;
    auto lamnda = [x](int y){return x+y;};
    std::cout<<lamnda(2);
*/



    return 0;
}

