#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include<vector>

template<typename VectorT, unsigned size>
inline void BubbleSortClassic(VectorT& data)
{
    for(unsigned j = 0; j < size; ++j) //convertir en recursivo
    {
        if(data[j] > data[j+1]) //swap
        {
            auto aux = data[j];
            data[j] = data[j+1];
            data[j+1] = aux;
        }
    }

    if constexpr(size > 2)
    {
        BubbleSortClassic<VectorT, size-1>(data);
    }
}



template <typename VectorT, int I, int J>
struct BubbleSortSwap
{
    static void Swap(VectorT& data)
    {
        if(data[I] > data[J])
        {
            auto aux = data[I];
            data[I] = data[J];
            data[J] = aux;
        }
    }

};


template<typename VectorT, int Size, int J>
struct BubbleSortLoop
{
    enum {Flag = (J <= Size-2)}; //true->iterar!!! false->stop

    static void Loop(VectorT& data)
    {
        //Swap
        BubbleSortSwap<VectorT, J, J+1>::Swap(data);
        if constexpr (J <= Size-2)
        {
            //BubbleSortLoop<VectorT, Flag ? Size: -1, Flag?(J+1): -1>::Loop(data);
            BubbleSortLoop<VectorT, Size, J+1>::Loop(data);
        }

    }

};


template <typename VectorT, int Size>
struct BubbleSort
{
    static void Sort(VectorT& data)
    {
        BubbleSortLoop<VectorT, Size-1, 0>::Loop(data);//loop interno -> swaps
        if constexpr(Size > 2)
        {
            BubbleSort<VectorT, Size-1>::Sort(data); //loop experno
        }
    }
};


//criterio parada
//template <typename VectorT>
//struct BubbleSort<VectorT, 1>
//{
//    static void Sort(VectorT&){}
//};


//template<typename VectorT>
//struct BubbleSortLoop<VectorT, -1, -1>
//{
//    static void Loop(VectorT&){}

//};






















































#endif // BUBBLESORT_H
