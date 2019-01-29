cmake_minimum_required(VERSION 3.13)
project(record_tracker)
set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.68.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest main.cpp)

add_executable(record_tracker main.cpp records.cpp records.h boxset.cpp boxset.h node.cpp node.h seven.cpp seven.h table.cpp table.h seventy_eights.cpp seventy_eights.h main.h twelve.cpp twelve.h)