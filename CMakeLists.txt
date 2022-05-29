cmake_minimum_required(VERSION 3.3)
project("vtyrimai" LANGUAGES C CXX)
add_executable(vtyrimai main.cpp)
set_property(TARGET vtyrimai PROPERTY CXX_STANDARD 17)