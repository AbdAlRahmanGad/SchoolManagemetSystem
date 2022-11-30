cmake_minimum_required(VERSION 3.21)
project(SchoolManagemetSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(SchoolManagemetSystem
        main.cpp
        Student.h Student.cpp
        StudentController.h StudentController.cpp
        SubjectController.h SubjectController.cpp
        SubjectData.h SubjectData.cpp
        SubjectDefinition.h SubjectDefinition.cpp)