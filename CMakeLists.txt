cmake_minimum_required(VERSION 3.29)
project(test_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(include/glad)
include_directories(include/GLFW)
include_directories(include/KHR)
include_directories(lib)
include_directories(lib/cmake)
include_directories(lib/cmake/glfw3)
include_directories(src)

include(FetchContent)

add_executable(test_project
    include/glad/glad.h
    include/GLFW/glfw3.h
    include/GLFW/glfw3native.h
    include/KHR/khrplatform.h
    include/linmath.h
    lib/cmake/glfw3/glfw3Config.cmake
    lib/cmake/glfw3/glfw3ConfigVersion.cmake
    lib/cmake/glfw3/glfw3Targets-noconfig.cmake
    lib/cmake/glfw3/glfw3Targets.cmake
    lib/pkgconfig/glfw3.pc
    src/glad.c
        triangle.cpp
        shader.hpp
        shader.cpp
        Rectangle.cpp
        Rectangle.h
        matrix.h
        cube.cpp
)


target_link_libraries(test_project -lglew32 -lopengl32)

