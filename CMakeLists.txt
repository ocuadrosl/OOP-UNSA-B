cmake_minimum_required(VERSION 3.5)

project(OOP-UNSA-B LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS -pthread)
#find_package(Threads) -> windows users


file(GLOB files "*.h" "*.cpp")

add_executable(OOP-UNSA-B  ${files}  main.cpp) #linking
