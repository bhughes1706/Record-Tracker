cmake_minimum_required(VERSION 3.13)
project(record_tracker)

set(CMAKE_CXX_STANDARD 14)

add_executable(record_tracker main.cpp records.cpp records.h boxset.cpp boxset.h node.cpp node.h seven.cpp seven.h list.cpp list.h)