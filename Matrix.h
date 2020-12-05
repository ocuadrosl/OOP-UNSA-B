#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
#include <numeric>
#include <chrono>
#include <thread>
#include <future>

namespace myThread
{
template <typename DataType>
class Matrix
{
    using RowType = std::vector<DataType>;
    using MatrixType  = std::vector<RowType>;

    MatrixType Data{};

    std::size_t Rows{};
    std::size_t Columns{};

public:
    Matrix();
    Matrix(const std::size_t& rows, const std::size_t& columns);

    const RowType& operator[](unsigned rowIndex) const {return Data[rowIndex];}
    RowType& operator[](unsigned rowIndex) {return Data[rowIndex];}

    DataType ComputeInnerSum();
    DataType ComputeInnerSumThread();
    DataType ComputeInnerSumThreadV2(); //C++ style



};


template <typename DataType>
Matrix<DataType>::Matrix():
    Data{MatrixType(0, RowType(0, DataType{}))},
    Rows{0},
    Columns{0}
{


}

template<typename DataType>
Matrix<DataType>::Matrix(const std::size_t& rows, const std::size_t& columns):
    Data{ MatrixType(rows, RowType(columns, DataType{} ))},
    Rows{rows},
    Columns{columns}
{
    std::cout<<"explicit"<<"\n";
}

template<typename DataType>
DataType Matrix<DataType>::ComputeInnerSumThreadV2()
{

    std::vector<std::future<DataType>> rowSums(Rows);

    for(unsigned rowIndex=0; rowIndex< Rows; ++rowIndex)
    {
        rowSums[rowIndex] = std::async(std::accumulate<typename RowType::const_iterator, DataType>,  Data[rowIndex].begin(), Data[rowIndex].end(), DataType{});
    }



}

template<typename DataType>
DataType Matrix<DataType>::ComputeInnerSumThread()
{

    auto start = std::chrono::steady_clock::now();

    auto accumulate = [this](unsigned rowIndex, DataType& sum)
    {
        sum = std::accumulate(Data[rowIndex].begin(), Data[rowIndex].end(), DataType{});
    };

    std::vector<std::thread> threads;
    std::vector<DataType> rowSums(Rows, DataType{});

    //creating
    for(unsigned rowIndex=0; rowIndex<Rows; ++rowIndex)
    {
        threads.emplace_back(std::thread(accumulate, rowIndex , std::ref(rowSums[rowIndex])));
    }

    //exect
    for(auto& thread: threads)
    {
        thread.join();
    }


    DataType totalSum = std::accumulate( rowSums.begin(), rowSums.end(), DataType{});

    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> seconds = end - start;
    std::cout << "time: " << seconds.count() << "s\n";



    return totalSum;

}

template<typename DataType>
DataType Matrix<DataType>::ComputeInnerSum()
{

    auto start = std::chrono::steady_clock::now();

    DataType sum{} ;
    for(auto row:Data)
    {
        sum +=  std::accumulate(row.begin(), row.end(), DataType{} );
    }

    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> seconds = end - start;
    std::cout << "time: " << seconds.count() << "s\n";

    return sum;
}

template<typename DataType>
DataType ComputeInnerSumThread()
{


}


}




#endif // MATRIX_H
