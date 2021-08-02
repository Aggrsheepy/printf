cmake_minimum_required(VERSION 3.19)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ft_printf
        ft_printf.c
        ft_atoi.c
        ft_itoa.c
        ft_itoa_base_mod.c
        ft_strlen.c
        ft_strchr.c
        ft_print_str.c
        ft_print_int.c
        ft_print_char.c
        ft_print_hex.c
        ft_print_uint.c
        ft_print_p.c
        ft_print_proc.c
        init_struct.c
        ft_substr.c
        ft_check_weight.c
        print_sleva.c
        print_sprava.c
        ft_obrab.c
        null_struct.c

#        main_c.c     #ok
#        main_s.c       # not ok *
#      main_i.c
#        main_d.c
#        main_p.c
#    main_u.c
#    main_x.c
#     main_bigx.c
        printf.h)
