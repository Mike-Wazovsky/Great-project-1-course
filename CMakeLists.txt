cmake_minimum_required(VERSION 3.10)
project(macaftc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/Users/milyausha/qt/5.9.9/clang_64")
find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

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

target_link_libraries(macaftc Qt5::Widgets)
