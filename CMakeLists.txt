cmake_minimum_required(VERSION 3.9)
project(Rush_MIMI)

set(CMAKE_CXX_STANDARD 11)

add_executable(Rush_MIMI
        Bullet.cpp
        Bullet.hpp
        Enemy.cpp
        Enemy.hpp
        main.cpp
        Moves.cpp
        Moves.hpp
        Player.cpp
        Player.hpp
        Ship.cpp
        Ship.hpp
        Window.cpp
        Window.hpp)
