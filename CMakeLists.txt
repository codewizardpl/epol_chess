cmake_minimum_required(VERSION 2.8)

project(epol_chess CXX)

include_directories(include)

set(source
    "src/Board.cpp"
    "src/ConsoleDisplay.cpp"
    "src/Figure.cpp"
    "src/Game.cpp")

add_executable(${PROJECT_NAME} ${source})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED true)

