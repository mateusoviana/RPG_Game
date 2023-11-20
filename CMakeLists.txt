cmake_minimum_required(VERSION 3.26)
project(RPG_Game)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(RPG_Game
        Game.cpp
        Game.hpp
        Graph.cpp
        Graph.hpp
        main.cpp
        PriorityQueue.hpp
        PriorityQueue.cpp)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(RPG_Game sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

include_directories(/usr/bin/include)