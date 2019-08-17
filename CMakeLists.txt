cmake_minimum_required(VERSION 3.15)
project(colorply)

SET(EXECUTABLE_OUTPUT_PATH bin)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)

link_libraries(
    m
    pthread
    X11
)


include_directories(
    ./include
    ./happly
    ./pugixml/src
    ./eigen-git-mirror
    ./CImg
)

add_executable(
    colorply
    src/commands.cpp
    src/functions.cpp
    src/ioply.cpp
    src/ioxml.cpp
    src/main.cpp
    pugixml/src/pugixml.cpp
    src/Image.cpp
    src/Camera.cpp
    src/processing.cpp
    src/ioimage.cpp
)

add_executable(
    test
    src/commands.cpp
    src/functions.cpp
    src/ioply.cpp
    src/ioxml.cpp
#    src/main.cpp
    pugixml/src/pugixml.cpp
    src/Image.cpp
    src/Camera.cpp
    src/processing.cpp
    src/ioimage.cpp
)