cmake_minimum_required(VERSION 3.20)
project(TicTacToeWithAI)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToeWithAI main.cpp
            Player.cpp Player.h
            Environment.cpp Environment.h
            Random.h Random.cpp
            Game.cpp Game.h)
