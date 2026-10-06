cmake_minimum_required(VERSION 3.16)

project(AdaptiCore)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AdaptiCore
    src/main.cpp
    src/core/Grid.cpp
    src/core/Combat.cpp
    src/entities/Player.cpp
    src/entities/Enemy.cpp
    src/core/Environment.cpp
)

target_include_directories(AdaptiCore PRIVATE include)