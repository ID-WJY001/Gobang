#include "include/board.h"
#include <cassert>
#include <iostream>

static void test_horizontal() {
    Board b; for (int c=0;c<5;++c) b.place(7,c,1);
    assert(b.isWin(7,2) && "horizontal five should win");
}
static void test_vertical() {
    Board b; for (int r=0;r<5;++r) b.place(r,9,2);
    assert(b.isWin(3,9) && "vertical five should win");
}
static void test_diag_down() {
    Board b; for (int k=0;k<5;++k) b.place(2+k,3+k,1);
    assert(b.isWin(4,5) && "diag down-right five should win");
}
static void test_diag_up() {
    Board b; for (int k=0;k<5;++k) b.place(10-k,4+k,2);
    assert(b.isWin(7,7) && "diag up-right five should win");
}

int main(){
    test_horizontal();
    test_vertical();
    test_diag_down();
    test_diag_up();
    std::cout << "Board::isWin basic tests passed\n";
    return 0;
}
