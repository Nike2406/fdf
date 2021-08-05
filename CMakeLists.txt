cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(./libft ./minilibx_macos)
add_executable(fdf fdf.h
        src/fdf.c
        get_next_line/get_next_line.h
        src/read_file.c
        src/utils.c
        get_next_line/get_next_line.c
        )
target_link_libraries(fdf libft mlx)