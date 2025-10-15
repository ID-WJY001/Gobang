#pragma once
#include "board.h"
#include <utility>
#include <cstdint>

// 返回 (row, col)
std::pair<int,int> ai_best_move(const Board& b, uint8_t color, int depth = 2);
