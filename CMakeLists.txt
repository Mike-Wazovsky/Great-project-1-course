cmake_minimum_required(VERSION 3.17)
project(Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (MSVC)
    add_compile_options(/W4 /WX)
    # Do not specify /O2 because there are Debug/Release modes.
else()
    if (NOT DEFINED CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug) # Add debug information
    endif (NOT DEFINED CMAKE_BUILD_TYPE)

    add_compile_options(-Wall -Wextra -Werror -O2)
    if (UNIX AND NOT DEFINED CMAKE_CXX_FLAGS) # Do not add if -DCMAKE_CXX_FLAGS is passed
        add_compile_options(-fsanitize=address)
        add_link_options(-fsanitize=address)
    endif (UNIX AND NOT DEFINED CMAKE_CXX_FLAGS)
endif (MSVC)

add_executable(macaftc src/main.cpp)
target_sources(macaftc PRIVATE src/game.cpp src/view.cpp src/controller.cpp src/uml.cpp)

include_directories(include)

add_library(common OBJECT src/main.cpp src/game.cpp src/view.cpp src/controller.cpp src/uml.cpp)