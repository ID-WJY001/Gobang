#include "board.h"
#include <algorithm>

Board::Board() : g_{} {}

bool Board::place(int r, int c, uint8_t color) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    if (g_[r][c] != 0) return false;
    g_[r][c] = color;
    return true;
}

void Board::remove(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return;
    g_[r][c] = 0;
}

static bool fiveInLine(const Board::Grid& g, int r, int c) {
    int color = g[r][c];
    if (!color) return false;
    const int dirs[4][2] = {{1,0},{0,1},{1,1},{1,-1}};
    for (auto &d : dirs) {
        int cnt = 1;
        for (int k=1; k<5; ++k) {
            int rr=r+k*d[0], cc=c+k*d[1];
            if (rr<0||rr>=Board::N||cc<0||cc>=Board::N||g[rr][cc]!=color) break;
            ++cnt;
        }
        for (int k=1; k<5; ++k) {
            int rr=r-k*d[0], cc=c-k*d[1];
            if (rr<0||rr>=Board::N||cc<0||cc>=Board::N||g[rr][cc]!=color) break;
            ++cnt;
        }
        if (cnt >= 5) return true;
    }
    return false;
}

bool Board::isWin(int r, int c) const {
    return fiveInLine(g_, r, c);
}

bool Board::isForbidden(int, int) const {
    // TODO: 后续接入禁手规则；当前占位返回 false
    return false;
}
