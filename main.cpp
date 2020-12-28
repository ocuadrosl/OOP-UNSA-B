#include <iostream> //global files
#include <memory>
#include "Vehicle.h" //local files
#include "Car.h"
#include <vector>
#include "Queen.h"
#include "Pawn.h"
#include "FunctionObject.h"
#include "MyVector.h"
#include "Utils.h"
#include "OperatorOverloading.h"
#include "Factorial.h"
#include "Fibonacci.h"
#include "BubbleSort.h"


#include <functional>

#include "ComplexNumber.h"
#include "Taxiab.h"
#include "Pell.h"
#include "Matrix.h"
#include "Singleton.h"
#include "GeometricShape.h"



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

void var(int x)
{
    std::cout << x <<"\n";
}

void var(const oopb::MyVector& a)
{
    std::cout << a[2] <<"\n";
}


int main()
{

    auto printShape = [](std::unique_ptr<GeometricShape> gs)
    {
        std::cout<<gs->Volume()<<"\n";
    };

    std::unique_ptr<GeometricShape> cube = std::make_unique<Cube>();
    //printShape(std::move(cube));


    Sphere sphere;
    std::cout<<sphere.GetName()<<"\n";

    std::unique_ptr<SphereAdapter> adaptedSphere = std::make_unique<SphereAdapter>(sphere);
    adaptedSphere->SetRadius(10);
    std::unique_ptr<GeometricShape> adaptedSpherePol = std::move(adaptedSphere);
    printShape(std::move(adaptedSpherePol));




    std::cout<<sphere.GetName()<<"\n";



 /*   new Manager{}; //crea singleton

    Manager& m1{Manager::GetSingleton()};
    m1.SetId(1);
    m1.PrintId();

    Manager& m2{Manager::GetSingleton()};
    m2.PrintId();

    Manager& m3{Manager::GetSingleton()};
    m3.PrintId();

    delete Manager::GetSingletonPointer();
*/

/*
    myThread::Matrix<ComplexNumber> m{50,70};

    m[0][0] = {-10, 4};
    m[0][1] = {20, 9};



    myThread::Matrix<ComplexNumber>::Iterator it = m.Begin();
    *it = {12,-9};
    //std::cout<<*it<<"\n";


    for( auto it = m.Begin(); it!=m.End(); ++it)
    {
        std::cout<<*it<<"\n";
    }
*/


    /*
    std::cout<<m.ComputeInnerSum()<<"\n";
    std::cout<<m.ComputeInnerSumThread()<<"\n";
    std::cout<<m.ComputeInnerSumThreadV2()<<"\n";
*/





/*
    std::cout<<Pell<5>::Result<<"\n";
*/

/*
    Taxiab taxiab;
    std::cout<<taxiab({1,2,3}, {3,2,1})<<"\n";
    std::cout<<taxiab({1,2,3}, {7,2,1})<<"\n";
    std::cout<<taxiab({1,2,3}, {3,2,1})<<"\n";
*/

/*
    ComplexNumber a{2, 7}, b{3, -4}, test{0,0};

    auto c = a * b ;

    std::cout<<test<<"\n";
*/
    /*

    constexpr int x = 5;
    std::vector<int> data(x, 0);
    data[4] = 0;
    data[3] = 1;
    data[2] = -5;
    data[1] = 3;
    data[0] = 4;

    BubbleSortClassic<std::vector<int>, x-1> (data);



    BubbleSort<std::vector<int>, 5>::Sort(data);
    for(auto val: data)
    {
       std::cout<<val<<"\n";
    }
*/



  /*  constexpr unsigned x=10;
    unsigned y=11;

    auto fi = Fibonacci<x>::Result;
    auto fic = FibonacciConst(x);

    std::cout<<fic<<std::endl;
*/

    //auto fa = FactorialRegular(10);
    //auto fac = Factorial<10>::Result;

    //std::cout<<fac<<"\n";


/*
    //implicit cast!!!!

    oopb::MyVector a{10}, b{10};

    a[1] = 4;
    b[1] = 40;


    std::vector<int> v(10,1), w(10,2);

    //alias types
    using MyVector  = oopb::MyVector; //alias tipo de dato
    using stdVector = std::vector<int>; //alias tipo de dato

    //alias functions
    const auto& EuclideanDistance = utils::EuclideanDistance<MyVector, stdVector, 10>;


    auto dm  = EuclideanDistance(a, v);
    auto dm2 = EuclideanDistance(a, v);


    auto ds = utils::EuclideanDistance<std::vector<int>, std::vector<int>, 10>(v, w);

    std::cout<<ds<<"\n";
*/

    /*oopb::MyVector a{10}, b{10};

    a[1] = 10;
    b[1] = 9;

    a.At(1) = 9;

    std::cout << a[2] <<"\n";
    std::cout << b <<"\n";

    std::cout << (b >= a)<<std::endl;
    */

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

