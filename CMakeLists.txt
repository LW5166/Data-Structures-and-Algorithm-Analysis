cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 11)

add_executable(P1 "${CMAKE_CURRENT_SOURCE_DIR}/Day01/P1.c")
add_executable(D2p1 "${CMAKE_CURRENT_SOURCE_DIR}/Day02/P1_factorial.c")
add_executable(D2p2 "${CMAKE_CURRENT_SOURCE_DIR}/Day02/P2_print_out.c")
add_executable(D2p3 "${CMAKE_CURRENT_SOURCE_DIR}/Day02/P3_fib.c")