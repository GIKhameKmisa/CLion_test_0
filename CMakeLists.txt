cmake_minimum_required(VERSION 3.17)
project(test_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(test_0 main.c)
add_executable(ac01 S1E30/ac01.c)
add_executable(ac02 S1E30/ac02.c)
add_executable(ac03 S1E28/ac03.c)

add_executable(md5 S1E30/md5.c)
