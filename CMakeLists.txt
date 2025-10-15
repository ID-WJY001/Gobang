cmake_minimum_required(VERSION 3.20)
project(GobangEasyX CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 可选：仅用于逻辑单元测试（不含 UI）。
add_library(gobang_core
    src/board.cpp
    src/ai.cpp
)

target_include_directories(gobang_core PUBLIC include)

# UI 仍由 Visual Studio 项目构建；若需要 CMake 集成 UI，请自行链接 EasyX 与 winmm
# add_executable(gobang main.cpp)
# target_link_libraries(gobang PRIVATE gobang_core easyx winmm)

# Tests (logic only)
add_executable(board_iswin_test tests/board_iswin_test.cpp)
target_link_libraries(board_iswin_test PRIVATE gobang_core)
