#ifndef SINGLETON_H
#define SINGLETON_H

#include <cassert>
#include <iostream>

template<typename Type> //Type es la clase
class Singleton
{
    static Type* Instance;

public:
    Singleton()
    {
        assert( Instance == nullptr );// no se ha creado un objeto todavia!!
        Instance = static_cast<Type*>(this); //crear singleton
        std::cout<<"Crating Singleton [OK]\n";
    }

    static Type& GetSingleton()
    {
        return *Instance;
    }
    static Type* GetSingletonPointer()
    {
        return Instance;
    }
    virtual ~Singleton()
    {
        Instance = nullptr;
    }

};

template <typename Type>
Type* Singleton<Type>::Instance = nullptr;


class Manager : public Singleton<Manager>
{

    unsigned Id{0};
public:

    void SetId(unsigned id){ Id = id;}
    void PrintId()const
    {
        std::cout<<"Id: "<<Id<<"\n";
    }

};








#endif // SINGLETON_H
