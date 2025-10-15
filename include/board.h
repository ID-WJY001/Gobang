#pragma once
#include <array>
#include <cstdint>

// 15x15 五子棋棋盘；0=空，1=黑，2=白
class Board {
public:
    static constexpr int N = 15;
    using Grid = std::array<std::array<uint8_t, N>, N>;

    Board();

    // 在 (r,c) 落子；color: 1=黑,2=白；成功返回 true
    bool place(int r, int c, uint8_t color);

    // 撤子（用于搜索）
    void remove(int r, int c);

    // 胜负判定：若 (r,c) 处刚落子，是否形成五连
    bool isWin(int r, int c) const;

    // 禁手判定（仅对黑方常见规则）
    bool isForbidden(int r, int c) const;

    const Grid& grid() const { return g_; }
    Grid& grid() { return g_; }

private:
    Grid g_{}; // 初始化为 0
};
