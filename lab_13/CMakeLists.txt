cmake_minimum_required(VERSION 3.10)

project(Car)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

include_directories(include)

add_library(LibCar src/car.c)

add_executable(main src/main.c)

target_link_libraries(main LibCar)

set(CMAKE_INSTALL_RPATH ".")