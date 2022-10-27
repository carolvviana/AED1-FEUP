cmake_minimum_required(VERSION 3.23)
project(AED_Project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AED_Project1
        main.cpp
        UCClass.cpp
        UCClass.h
        Request.cpp
        Request.h
        Lecture.cpp
        Lecture.h
        Student.cpp
        Student.h
        Data.cpp
        Data.h
        )
