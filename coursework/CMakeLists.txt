cmake_minimum_required(VERSION 3.10)
project(FrequencyAnalysis C)
set(CMAKE_C_STANDARD 99)

add_executable(analyzer_prog main.c)

add_executable(run_unit_tests test_main.c)
target_link_libraries(run_unit_tests cmocka)
