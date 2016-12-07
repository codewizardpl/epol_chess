cmake_minimum_required(VERSION 2.8)

project(epol_chess CXX)

include_directories(include)

set(source
    "src/Board.cpp"
    "src/ConsoleDisplay.cpp"
    "src/Figure.cpp"
    "src/Game.cpp"
    "src/FigurePath.cpp"
    "src/GameLogic.cpp"
    "src/ConsolePlayer.cpp"
    "src/Player.cpp"
    "src/FigurePawn.cpp"
    "src/FigureKing.cpp"
    "src/FigureQueen.cpp"
    "src/FigureRook.cpp"
    "src/FigureKnight.cpp"
    "src/FigureBishop.cpp")

add_executable(${PROJECT_NAME} ${source})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED true)

