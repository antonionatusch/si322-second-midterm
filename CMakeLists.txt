cmake_minimum_required(VERSION 3.27)
project(si322_second_midterm)

set(CMAKE_CXX_STANDARD 20)

add_executable(si322_second_midterm src/main.cpp
        src/SmokeSemaphore.cpp
        include/SmokeSemaphore.h
        src/Agent.cpp
        include/Agent.h
        src/Smoker.cpp
        include/Smoker.h
        include/Worker.h
        src/Worker.cpp
        include/BicycleSemaphore.h
        include/Mounter.h
        src/Mounter.cpp
        src/BicycleSemaphore.cpp
        include/Menu.h
        src/Menu.cpp
        include/Global.h
        src/Global.cpp)
