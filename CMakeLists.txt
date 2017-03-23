cmake_minimum_required(VERSION 3.7.2)

SET(CMAKE_C_COMPILER C:/MinGW/bin/gcc.exe)
SET(CMAKE_CXX_COMPILER C:/MinGW/bin/g++.exe)
set(CMAKE_CXX_STANDARD 11)

project(C++Lecture_Exercises)
include_directories(include)
file(GLOB SOURCES "source/*.cpp" "include/*.hpp")
add_executable(main ${SOURCES})
#make - mngw32-make