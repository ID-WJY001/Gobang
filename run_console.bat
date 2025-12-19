@echo off
echo Compiling Console Gobang...
g++ main.cpp src/game_state.cpp src/game_rules.cpp src/ai_engine.cpp src/board.cpp -I include -o gobang.exe
if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b 1
)
echo Compilation successful!
gobang.exe
