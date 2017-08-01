cmake_minimum_required(VERSION 2.8)

project(epol_chess CXX)
find_package(Protobuf REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(include proto)
ADD_SUBDIRECTORY(proto)

set(source
    "src/Position.cpp"
    "src/PositionFormat.cpp"
    "src/Move.cpp"
    "src/Figure.cpp"
    "src/FigureSymbol.cpp"
    "src/Board.cpp"
    "src/ConsoleDisplay.cpp"
    "src/IllegalMoveException.cpp"
    "src/Chess.cpp"
    "src/PuzzleGame.cpp"
    "src/ChessGame.cpp"
    "src/ConsolePlayer.cpp"
    "src/Player.cpp"
    "src/NetworkPlayer.cpp"
    "src/main.cpp")

add_executable(${PROJECT_NAME} ${source})
target_link_libraries(${PROJECT_NAME} proto ${Boost_SYSTEM_LIBRARY} ${PROTOBUF_LIBRARY})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED true)

