cmake_minimum_required(VERSION 3.19)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ft_printf
        ft_printf.c
        ft_atoi.c
        ft_strlen.c
        ft_strchr.c
        ft_print_str.c
        ft_print_int.c
        ft_strjoin.c
        ft_substr.c
        printf.h)
