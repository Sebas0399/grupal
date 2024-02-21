cmake_minimum_required(VERSION 3.27)
project(grupal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

find_package(SFML)
find_package(fmt)

add_executable(grupal main.cpp
        histograma.h
        prefixSum.h
        utils.h
        utils.h)
target_link_libraries(grupal fmt::fmt)
target_link_libraries(grupal sfml::sfml)