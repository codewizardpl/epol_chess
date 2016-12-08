cmake_minimum_required(VERSION 2.8)

project(epol_chess CXX)

find_package(Protobuf REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(include)


set(source
    "src/main.cpp"
    "src/move.pb.cc"
    "src/PuzzleGame.cpp"
    "src/ChessGame.cpp"
    "src/Board.cpp"
    "src/ConsoleDisplay.cpp"
    "src/Figure.cpp"
    "src/FigurePawn.cpp"
    "src/FigurePath.cpp"
    "src/GameLogic.cpp"
    "src/ConsolePlayer.cpp"
    "src/Player.cpp"
    "src/PuzzleLogic.cpp"
    "src/FigurePawn.cpp"
    "src/FigureKing.cpp"
    "src/FigureQueen.cpp"
    "src/FigureRook.cpp"
    "src/FigureKnight.cpp"
    "src/FigureBishop.cpp")

add_executable(${PROJECT_NAME} ${source})
target_link_libraries(${PROJECT_NAME} ${Boost_SYSTEM_LIBRARY} ${Protobuf_LIBRARIES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED true)

