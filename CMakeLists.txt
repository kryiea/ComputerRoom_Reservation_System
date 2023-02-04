cmake_minimum_required(VERSION 3.24)

project(ComputerRoom_Reservation_System)

set(CMAKE_CXX_STANDARD 17)

add_executable (main_c main.cpp Student.cpp Teacher.cpp Manager.cpp)
