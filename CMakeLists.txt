cmake_minimum_required(VERSION 3.27)
project(si322_second_midterm)

set(CMAKE_CXX_STANDARD 20)

add_executable(si322_second_midterm src/main.cpp
        include/HelloWorld.h
        src/HelloWorld.cpp
        src/SmokeSemaphore.cpp
        include/SmokeSemaphore.h
        src/Agent.cpp
        include/Agent.h
        src/Smoker.cpp
        include/Smoker.h)