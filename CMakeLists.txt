cmake_minimum_required(VERSION 3.14)
project(coursera)

set(CMAKE_CXX_STANDARD 17)

add_executable(coursera main.cpp)
add_executable(divide divide/main.cpp)
add_executable(sqrt-equation sqrt-equation/main.cpp)
add_executable(minimum-string minimum-string/main.cpp)