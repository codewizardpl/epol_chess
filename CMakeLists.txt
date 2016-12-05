cmake_minimum_required(VERSION 2.8)

project(epol_chess CXX)

include_directories(include)

set(source
    "src/Board.cpp"
    "src/ConsoleDisplay.cpp"
    "src/Figure.cpp"
    "src/Game.cpp")

add_executable(${PROJECT_NAME} ${source})

