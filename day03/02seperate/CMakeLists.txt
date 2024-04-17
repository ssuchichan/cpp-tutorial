cmake_minimum_required(VERSION 3.2)
project(02seperate)

set(CMAKE_CXX_STANDARD 17)

add_executable(02seperate main.cpp
        student.cpp
        student.h
        clock.cpp
        clock.h)
