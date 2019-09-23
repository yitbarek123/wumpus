cmake_minimum_required(VERSION 3.12)
project(wumpus)

set(CMAKE_CXX_STANDARD 14)

add_executable(wumpus wumpus/main.cpp wumpus/wumpus.cpp wumpus/wumpus.h)
