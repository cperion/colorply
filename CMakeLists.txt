cmake_minimum_required(VERSION 3.15)
project(colorply)

SET(EXECUTABLE_OUTPUT_PATH bin)


add_executable(colorply
    src/commands.cpp
    src/functions.cpp
    src/ioply.cpp
    src/ioxml.cpp
    src/main.cpp
    pugixml/src/pugixml.cpp
)

include_directories(
    ./include
    ./happly
    ./pugixml/src
    ./eigen-git-mirror
)