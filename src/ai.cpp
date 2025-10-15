#include "ai.h"
#include <limits>

static int evaluate(const Board& b, uint8_t color) {
    // 极简启发（后续可替换为你现有的一套评分）
    // 这里只统计己方连续子的最长长度做一个粗略打分
    const auto& g = b.grid();
    int best = 0;
    const int dirs[4][2] = {{1,0},{0,1},{1,1},{1,-1}};
    for (int r=0;r<Board::N;++r) for (int c=0;c<Board::N;++c) if (g[r][c]==color){
        for (auto &d: dirs){
            int cnt=1;
            for (int k=1;k<5;++k){
                int rr=r+k*d[0], cc=c+k*d[1];
                if (rr<0||rr>=Board::N||cc<0||cc>=Board::N||g[rr][cc]!=color) break;
                ++cnt;
            }
            if (cnt>best) best=cnt;
        }
    }
    return best*100;
}

static int minimax(Board& b, uint8_t me, uint8_t turn, int depth, int alpha, int beta) {
    // 简化：遍历所有空位（后续可加入邻域裁剪/候选生成）
    // 终止：深度 0 或无空位
    int empty = 0;
    for (int r=0;r<Board::N;++r) for (int c=0;c<Board::N;++c) if (b.grid()[r][c]==0) ++empty;
    if (depth==0 || empty==0) return evaluate(b, me) - evaluate(b, 3-me);

    int best = (turn==me) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

    for (int r=0;r<Board::N;++r){
        for (int c=0;c<Board::N;++c){
            if (b.grid()[r][c]!=0) continue;
            if (!b.place(r,c,turn)) continue;
            if (b.isWin(r,c)) {
                int val = (turn==me) ? 1000000 : -1000000;
                b.remove(r,c);
                return val;
            }
            int val = minimax(b, me, (uint8_t)(3-turn), depth-1, alpha, beta);
            b.remove(r,c);
            if (turn==me){
                if (val>best) best=val;
                if (val>alpha) alpha=val;
            } else {
                if (val<best) best=val;
                if (val<beta) beta=val;
            }
            if (beta<=alpha) return best;
        }
    }
    return best;
}

std::pair<int,int> ai_best_move(const Board& board, uint8_t color, int depth) {
    Board b = board; // 拷贝
    int bestVal = std::numeric_limits<int>::min();
    std::pair<int,int> best = {-1,-1};
    for (int r=0;r<Board::N;++r){
        for (int c=0;c<Board::N;++c){
            if (b.grid()[r][c]!=0) continue;
            if (!b.place(r,c,color)) continue;
            if (b.isWin(r,c)) {
                b.remove(r,c);
                return {r,c};
            }
            int val = minimax(b, color, (uint8_t)(3-color), depth-1, std::numeric_limits<int>::min()/2, std::numeric_limits<int>::max()/2);
            b.remove(r,c);
            if (val>bestVal){ bestVal=val; best={r,c}; }
        }
    }
    return best;
}
