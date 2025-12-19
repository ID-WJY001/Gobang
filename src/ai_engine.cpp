#include "../include/ai_engine.h"
#include "../include/game_state.h"
#include "../include/game_rules.h"
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

int Cheng_5(int i, int j, int k) {
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i >= 0 && vis[i + 4][j] == flagcolor && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor && vis[i - 4][j] == flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j >= 0 && vis[i][j + 4] == flagcolor && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor) {
		cnt++;
	}
	if (j + 3 < 15 && j - 1 >= 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor) {
		cnt++;
	}
	if (j + 2 < 15 && j - 2 >= 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor) {
		cnt++;
	}
	if (j + 1 < 15 && j - 3 >= 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor) {
		cnt++;
	}
	if (j < 15 && j - 4 >= 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor && vis[i][j - 4] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j + 4 < 15 && j >= 0 && vis[i + 4][j + 4] == flagcolor && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && j + 3 < 15 && j - 1 >= 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 2 >= 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && j + 1 < 15 && j - 3 >= 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j < 15 && j - 4 >= 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == flagcolor && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j + 4 < 15 && j >= 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == flagcolor) {
		cnt++;
	}
	return cnt;
}
int Huo_4(int i, int j, int k) {//011110
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	return cnt;
}
int Dan_Huo_3(int i, int j, int k) {//001110 011100
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0 && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0 && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	return cnt;
}
int Tiao_Huo_3(int i, int j, int k) {//011010 010110
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	return cnt;
}
int Huo_2(int i, int j, int k) {//001100 010100 001010
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0 && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0 && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	return cnt;
}
int Chong_4_1(int i, int j, int k) {//011112 211110
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 3 - flagcolor && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 3 - flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 3 - flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 3 - flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 3 - flagcolor && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 3 - flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 3 - flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 3 - flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 3 - flagcolor && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 3 - flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 3 - flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 3 - flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 3 - flagcolor && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 3 - flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 3 - flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 3 - flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 3 - flagcolor) {
		cnt++;
	}
	return cnt;
}
int Chong_4_2(int i, int j, int k) {//10111 11011 11101
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i >= 0 && vis[i + 4][j] == flagcolor && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && vis[i + 4][j] == flagcolor && vis[i + 3][j] == flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && vis[i + 4][j] == flagcolor && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor && vis[i - 4][j] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == flagcolor && vis[i - 4][j] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0 && vis[i - 4][j] == flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j >= 0 && vis[i][j + 4] == flagcolor && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j >= 0 && vis[i][j + 4] == flagcolor && vis[i][j + 3] == flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j >= 0 && vis[i][j + 4] == flagcolor && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 1 >= 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor) {
		cnt++;
	}
	if (j + 3 < 15 && j - 1 >= 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor) {
		cnt++;
	}
	if (j + 2 < 15 && j - 2 >= 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor) {
		cnt++;
	}
	if (j + 2 < 15 && j - 2 >= 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor) {
		cnt++;
	}
	if (j + 1 < 15 && j - 3 >= 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor) {
		cnt++;
	}
	if (j + 1 < 15 && j - 3 >= 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == flagcolor) {
		cnt++;
	}
	if (j < 15 && j - 4 >= 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor && vis[i][j - 4] == flagcolor) {
		cnt++;
	}
	if (j < 15 && j - 4 >= 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == flagcolor && vis[i][j - 4] == flagcolor) {
		cnt++;
	}
	if (j < 15 && j - 4 >= 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0 && vis[i][j - 4] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j + 4 < 15 && j >= 0 && vis[i + 4][j + 4] == flagcolor && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j + 4 < 15 && j >= 0 && vis[i + 4][j + 4] == flagcolor && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j + 4 < 15 && j >= 0 && vis[i + 4][j + 4] == flagcolor && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && j + 3 < 15 && j - 1 >= 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && j + 3 < 15 && j - 1 >= 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 2 >= 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 2 >= 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && j + 1 < 15 && j - 3 >= 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && j + 1 < 15 && j - 3 >= 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j < 15 && j - 4 >= 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j < 15 && j - 4 >= 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j < 15 && j - 4 >= 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j - 4 >= 0 && j < 15 && vis[i + 4][j - 4] == flagcolor && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j - 4 >= 0 && j < 15 && vis[i + 4][j - 4] == flagcolor && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j - 4 >= 0 && j < 15 && vis[i + 4][j - 4] == flagcolor && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && j - 3 >= 0 && j + 1 < 15 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && j - 3 >= 0 && j + 1 < 15 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && j - 2 >= 0 && j + 2 < 15 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && j - 2 >= 0 && j + 2 < 15 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && j - 1 >= 0 && j + 3 < 15 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && j - 1 >= 0 && j + 3 < 15 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j >= 0 && j + 4 < 15 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j >= 0 && j + 4 < 15 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j >= 0 && j + 4 < 15 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == flagcolor) {
		cnt++;
	}
	return cnt;
}
int Mian_3_1(int i, int j, int k) {//001112 211100 010112 211010 011012 210110
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 3 - flagcolor && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 3 - flagcolor && vis[i + 3][j] == flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 3 - flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 3 - flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 3 - flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 3 - flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 3 - flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0 && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 3 - flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 3 - flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 3 - flagcolor && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 3 - flagcolor && vis[i][j + 3] == flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 3 - flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i - 2][j] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 3 - flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 3 - flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 3 - flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 3 - flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0 && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 3 - flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 3 - flagcolor && vis[i][j] - 1 == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 3 - flagcolor && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 3 - flagcolor && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 3 - flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 3 - flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 3 - flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 3 - flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 3 - flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 3 - flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 3 - flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 3 - flagcolor && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 3 - flagcolor && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 3 - flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 3 - flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 3 - flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 3 - flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 3 - flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 3 - flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 3 - flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 3 - flagcolor) {
		cnt++;
	}
	return cnt;
}
int Mian_3_2(int i, int j, int k) {//10011 11001 10101
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i >= 0 && vis[i + 4][j] == flagcolor && vis[i + 3][j] == flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && vis[i + 4][j] == flagcolor && vis[i + 3][j] == 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && vis[i + 4][j] == flagcolor && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == 0 && vis[i - 3][j] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == 0 && vis[i - 3][j] == flagcolor && vis[i - 4][j] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == 0 && vis[i - 4][j] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0 && vis[i - 4][j] == flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j >= 0 && vis[i][j + 4] == flagcolor && vis[i][j + 3] == 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j >= 0 && vis[i][j + 4] == flagcolor && vis[i][j + 3] == flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j >= 0 && vis[i][j + 4] == flagcolor && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 1 >= 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor) {
		cnt++;
	}
	if (j + 2 < 15 && j - 2 >= 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor) {
		cnt++;
	}
	if (j + 1 < 15 && j - 3 >= 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == 0 && vis[i][j - 3] == flagcolor) {
		cnt++;
	}
	if (j < 15 && j - 4 >= 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0 && vis[i][j - 4] == flagcolor) {
		cnt++;
	}
	if (j < 15 && j - 4 >= 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == 0 && vis[i][j - 3] == flagcolor && vis[i][j - 4] == flagcolor) {
		cnt++;
	}
	if (j < 15 && j - 4 >= 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == 0 && vis[i][j - 4] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j + 4 < 15 && j >= 0 && vis[i + 4][j + 4] == flagcolor && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j + 4 < 15 && j >= 0 && vis[i + 4][j + 4] == flagcolor && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j + 4 < 15 && j >= 0 && vis[i + 4][j + 4] == flagcolor && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && j + 3 < 15 && j - 1 >= 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 2 >= 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && j + 1 < 15 && j - 3 >= 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j < 15 && j - 4 >= 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j < 15 && j - 4 >= 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j < 15 && j - 4 >= 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j - 4 >= 0 && j < 15 && vis[i + 4][j - 4] == flagcolor && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j - 4 >= 0 && j < 15 && vis[i + 4][j - 4] == flagcolor && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j - 4 >= 0 && j < 15 && vis[i + 4][j - 4] == flagcolor && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 1 >= 0 && j - 3 >= 0 && j + 1 < 15 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 2 >= 0 && j - 2 >= 0 && j + 2 < 15 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 3 >= 0 && j - 1 >= 0 && j + 3 < 15 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j >= 0 && j + 4 < 15 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j >= 0 && j + 4 < 15 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == flagcolor) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j >= 0 && j + 4 < 15 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == flagcolor) {
		cnt++;
	}
	return cnt;
}
int Mian_3_3(int i, int j, int k) {//2011102
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i - 2 >= 0 && vis[i + 4][j] == 3 - flagcolor && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 3 >= 0 && vis[i + 3][j] == 3 - flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 4 >= 0 && vis[i + 2][j] == 3 - flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0 && vis[i - 4][j] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j - 2 >= 0 && vis[i][j + 4] == 3 - flagcolor && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 3 < 15 && j - 3 >= 0 && vis[i][j + 3] == 3 - flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 2 < 15 && j - 4 >= 0 && vis[i][j + 2] == 3 - flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0 && vis[i][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 2 >= 0 && j + 4 < 15 && j - 2 >= 0 && vis[i + 4][j + 4] == 3 - flagcolor && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 3 >= 0 && vis[i + 3][j + 3] == 3 - flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 4 >= 0 && j + 2 < 15 && j - 4 >= 0 && vis[i + 3][j + 3] == 3 - flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 2 >= 0 && j - 4 >= 0 && j + 2 < 15 && vis[i + 4][j - 4] == 3 - flagcolor && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 3 >= 0 && j - 3 >= 0 && j + 3 < 15 && vis[i + 3][j - 3] == 3 - flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j + 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 4 >= 0 && j - 2 >= 0 && j + 4 < 15 && vis[i + 2][j - 2] == 3 - flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j - 3] == 0 && vis[i - 4][j + 4] == 3 - flagcolor) {
		cnt++;
	}
	return cnt;
}
int Mian_2_1(int i, int j, int k) {//000112 211000 001012 210100 010012 210010
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 3 - flagcolor && vis[i + 3][j] == flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && vis[i + 4][j] == 0 && vis[i + 3][j] == flagcolor && vis[i + 2][j] == 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 3 - flagcolor && vis[i + 2][j] == flagcolor && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && vis[i + 3][j] == 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 3 - flagcolor && vis[i + 1][j] == flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == 0 && vis[i - 3][j] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 3 - flagcolor && vis[i - 1][j] == flagcolor && vis[i - 2][j] == 0 && vis[i - 3][j] == 0 && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 3 - flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == flagcolor && vis[i - 3][j] == 0 && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == 0 && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && vis[i + 1][j] == 3 - flagcolor && vis[i - 1][j] == 0 && vis[i - 2][j] == 0 && vis[i - 3][j] == flagcolor && vis[i - 4][j] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 3 - flagcolor && vis[i][j + 3] == flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == 0) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j - 1 >= 0 && vis[i][j + 4] == 0 && vis[i][j + 3] == flagcolor && vis[i][j + 2] == 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 3 - flagcolor && vis[i][j + 2] == flagcolor && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == 0) {
		cnt++;
	}
	if (j + 3 < 15 && j - 2 >= 0 && vis[i][j + 3] == 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == flagcolor && vis[i - 2][j] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 3 - flagcolor && vis[i][j + 1] == flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == 0 && vis[i][j - 3] == 0) {
		cnt++;
	}
	if (j + 2 < 15 && j - 3 >= 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 3 - flagcolor && vis[i][j - 1] == flagcolor && vis[i][j - 2] == 0 && vis[i][j - 3] == 0 && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 3 - flagcolor && vis[i][j - 1] == 0 && vis[i][j - 2] == 0 && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 3 - flagcolor && vis[i][j] - 1 == 0 && vis[i][j - 2] == flagcolor && vis[i][j - 3] == 0 && vis[i][j - 4] == 0) {
		cnt++;
	}
	if (j + 1 < 15 && j - 4 >= 0 && vis[i][j + 1] == 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == 0 && vis[i][j - 3] == flagcolor && vis[i][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 3 - flagcolor && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 4][j + 4] == 0 && vis[i + 3][j + 3] == flagcolor && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 3 - flagcolor && vis[i + 2][j + 2] == flagcolor && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 3 - flagcolor && vis[i + 1][j + 1] == flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 3 - flagcolor && vis[i - 1][j - 1] == flagcolor && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 3 - flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == flagcolor && vis[i - 4][j - 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 1][j + 1] == 3 - flagcolor && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == flagcolor && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 3 - flagcolor && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i - 1 >= 0 && j + 1 < 15 && j - 4 >= 0 && vis[i + 4][j - 4] == 0 && vis[i + 3][j - 3] == flagcolor && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 3 - flagcolor && vis[i + 2][j - 2] == flagcolor && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0) {
		cnt++;
	}
	if (i + 3 < 15 && i - 2 >= 0 && j + 2 < 15 && j - 3 >= 0 && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 3 - flagcolor && vis[i + 1][j - 1] == flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == 0) {
		cnt++;
	}
	if (i + 2 < 15 && i - 3 >= 0 && j + 3 < 15 && j - 2 >= 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 3 - flagcolor && vis[i - 1][j + 1] == flagcolor && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 3 - flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 0 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == flagcolor && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == 3 - flagcolor) {
		cnt++;
	}
	if (i + 1 < 15 && i - 4 >= 0 && j + 4 < 15 && j - 1 >= 0 && vis[i + 1][j - 1] == 3 - flagcolor && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == flagcolor && vis[i - 4][j + 4] == 0) {
		cnt++;
	}
	return cnt;
}
int Mian_2_2(int i, int j, int k) {//10001 
	int cnt = 0;
	int flagcolor = 0;
	if (k) {
		flagcolor = 2 - color;
	}
	else {
		flagcolor = color + 1;
	}
	if (i + 4 < 15 && i >= 0 && vis[i + 4][j] == flagcolor && vis[i + 3][j] == 0 && vis[i + 2][j] == 0 && vis[i + 1][j] == 0) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && vis[i - 1][j] == 0 && vis[i - 2][j] == 0 && vis[i - 3][j] == 0 && vis[i - 4][j] == flagcolor) {
		cnt++;
	}
	if (j + 4 < 15 && j >= 0 && vis[i][j + 4] == flagcolor && vis[i][j + 3] == 0 && vis[i][j + 2] == 0 && vis[i][j + 1] == 0) {
		cnt++;
	}
	if (j < 15 && j - 4 >= 0 && vis[i][j - 1] == 0 && vis[i][j - 2] == 0 && vis[i][j - 3] == 0 && vis[i][j - 4] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j + 4 < 15 && j >= 0 && vis[i + 4][j + 4] == flagcolor && vis[i + 3][j + 3] == 0 && vis[i + 2][j + 2] == 0 && vis[i + 1][j + 1] == 0) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j < 15 && j - 4 >= 0 && vis[i - 1][j - 1] == 0 && vis[i - 2][j - 2] == 0 && vis[i - 3][j - 3] == 0 && vis[i - 4][j - 4] == flagcolor) {
		cnt++;
	}
	if (i + 4 < 15 && i >= 0 && j - 4 >= 0 && j < 15 && vis[i + 4][j - 4] == flagcolor && vis[i + 3][j - 3] == 0 && vis[i + 2][j - 2] == 0 && vis[i + 1][j - 1] == 0) {
		cnt++;
	}
	if (i < 15 && i - 4 >= 0 && j >= 0 && j + 4 < 15 && vis[i - 1][j + 1] == 0 && vis[i - 2][j + 2] == 0 && vis[i - 3][j + 3] == 0 && vis[i - 4][j + 4] == flagcolor) {
		cnt++;
	}
	return cnt;
}

node GetBestMove(bool isBlack) {
	if (isBlack) {
		CalculateValuesBlack();
	} else {
		CalculateValuesWhite();
	}
	// Note: min_max_alpha_beta uses global 'vis' and 'value'
	// The original code called it with depth 2.
	// maximizing_player=1 means Black? 
	// In AI_Play_White (original): min_max_alpha_beta(vis, 2, -inf, inf, 1);
	// In AI_Play_Black (original): min_max_alpha_beta(vis, 2, -inf, inf, 1);
	// It seems maximizing_player is always 1 in the call?
	// Let's check min_max_alpha_beta implementation.
	// If maximizing_player is true, it tries to place Black (1).
	// If false, it tries to place White (2).
	
	// If AI is White, it should probably be maximizing White's score?
	// But the original code used '1' for both.
	// Let's stick to original logic:
	return min_max_alpha_beta(vis, 2, -100000000, 100000000, 1);
}

node max_node(node i, node j) {
	return i.value > j.value ? i : j;
}
node min_node(node i, node j) {
	return i.value < j.value ? i : j;
}
node min_max_alpha_beta(int vis[15][15], int depth, int alpha, int beta, bool maximizing_player) {
	if (depth == 0) {
		int maxn = -1000000000;
		node ppp;
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (!vis[i][j] && value[i][j] > maxn) {
					maxn = value[i][j];
					ppp.x = i;
					ppp.y = j;
				}
			}
		}
		return ppp;
	}
	if (maximizing_player) {
		node max_eval;
		max_eval.value = -1000000000;
		for (int row = 0; row < 15; ++row) {
			for (int col = 0; col < 15; ++col) {
				if (vis[row][col] == 0) {
					int new_vis[15][15];
					memcpy(new_vis, vis, sizeof(new_vis));
					new_vis[row][col] = 1;
					node eval_score;
					eval_score= min_max_alpha_beta(new_vis, depth - 1, alpha, beta, false);
					// ���µ�ǰ�ҵ����������ֵ��ȡ��ǰ�������ֵ���µõ�������ֵ�еĽϴ���
					max_eval = max_node(max_eval, eval_score);
					// ����alphaֵ��ȡ��ǰ�������ֵ������alphaֵ�еĽϴ��ߣ���Ϊ�µ�alphaֵ������alpha-beta��֦�ж�
					alpha = max(alpha, eval_score.value);
					// ����alpha-beta��֦�жϣ����betaֵС�ڵ���alphaֵ��˵����ǰ��֧�������ٲ������Ž����������������˵���Ѿ��ҵ�����С����ҵ���С�������ޱȵ�ǰ�ҵ������������޻�С����������û��Ҫ�����ˣ���ֱ������ѭ����ֹͣ�Ե�ǰ��ʣ��λ�õ�����
					if (beta <= alpha) {
						break;
					}
				}
			}
		}
		return max_eval;
	}
	else {
		node min_eval;
		min_eval.value= 1000000000;
		for (int row = 0; row < 15; ++row) {
			for (int col = 0; col < 15; ++col) {
				if (vis[row][col] == 0) {
					int new_vis[15][15];
					memcpy(new_vis, vis, sizeof(new_vis));
					new_vis[row][col] = 2;
					node eval_score = min_max_alpha_beta(new_vis, depth - 1, alpha, beta, true);
					// ���µ�ǰ�ҵ�����С����ֵ��ȡ��ǰ��С����ֵ���µõ�������ֵ�еĽ�С��
					min_eval = min_node(min_eval, eval_score);
					// ����betaֵ��ȡ��ǰ��С����ֵ������betaֵ�еĽ�С�ߣ���Ϊ�µ�betaֵ������alpha-beta��֦�ж�
					beta = min(beta, eval_score.value);
					// ����alpha-beta��֦�жϣ����betaֵС�ڵ���alphaֵ��˵����ǰ��֧�������ٲ������Ž����������С�������˵���Ѿ��ҵ��������ҵ����������ޱȵ�ǰ�ҵ�����С�������޻��󣬺�������û��Ҫ�����ˣ���ֱ������ѭ����ֹͣ�Ե�ǰ��ʣ��λ�õ�����
					if (beta <= alpha) {
						break;
					}
				}
			}
		}
		return min_eval;
	}
}

void CalculateValuesWhite() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {                                                      
			if (Cheng_5(i, j, 1)) {
				value[i][j] = 5000000;
			}
			else if (Cheng_5(i, j, 0)) {
				value[i][j] = 5000000;
			}
			else {
				value[i][j] = Huo_4(i, j, 1) * HUO_4_SCORE + (Chong_4_1(i, j, 1) + Chong_4_2(i, j, 1)) * CHONG_4_SCORE + Dan_Huo_3(i, j, 1) * DAN_HUO_3_SCORE + Tiao_Huo_3(i, j, 1) * TIAO_HUO_3_SCORE + (Mian_3_1(i, j, 1) + Mian_3_2(i, j, 1) + Mian_3_3(i, j, 1)) * MIAN_3_SCORE + Huo_2(i, j, 1) * HUO_2_SCORE + (Mian_2_1(i, j, 1) + Mian_2_2(i, j, 1)) * MIAN_2_SCORE;
				value[i][j] += Huo_4(i, j, 0) * 500000
					+ (Chong_4_1(i, j, 0) + Chong_4_2(i, j, 0)) * CHONG_4_SCORE
					+ Dan_Huo_3(i, j, 0) * DAN_HUO_3_SCORE
					+ Tiao_Huo_3(i, j, 0) * TIAO_HUO_3_SCORE
					+ (Mian_3_1(i, j, 0) + Mian_3_2(i, j, 0) + Mian_3_3(i, j, 0)) * MIAN_3_SCORE
					+ Huo_2(i, j, 0) * HUO_2_SCORE
					+ (Mian_2_1(i, j, 0) + Mian_2_2(i, j, 0)) * MIAN_2_SCORE;
				if (i >= 6 && i <= 8 && j >= 6 && j <= 8) {
					value[i][j]+=11;
				}
			}
		}
	}
}

void CalculateValuesBlack() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (IsForbiddenAt(i, j)) {
				value[i][j] = -1;
			}
			else if (Cheng_5(i, j ,1)) {
				value[i][j] = 5000000;
			}
			else if (Cheng_5(i, j, 0)) {
				value[i][j] = 5000000;
			}
			else {
				value[i][j] = Huo_4(i, j, 1) * HUO_4_SCORE + (Chong_4_1(i, j, 1) + Chong_4_2(i, j, 1)) * CHONG_4_SCORE + Dan_Huo_3(i, j, 1) * DAN_HUO_3_SCORE + Tiao_Huo_3(i, j, 1) * TIAO_HUO_3_SCORE + (Mian_3_1(i, j, 1) + Mian_3_2(i, j, 1) + Mian_3_3(i, j, 1)) * MIAN_3_SCORE + Huo_2(i, j, 1) * HUO_2_SCORE + (Mian_2_1(i, j, 1) + Mian_2_2(i, j, 1)) * MIAN_2_SCORE;
				value[i][j] += Huo_4(i, j, 0) * 500000 + (Chong_4_1(i, j, 0) + Chong_4_2(i, j, 0)) * CHONG_4_SCORE + Dan_Huo_3(i, j, 0) * DAN_HUO_3_SCORE + Tiao_Huo_3(i, j, 0) * TIAO_HUO_3_SCORE + (Mian_3_1(i, j, 0) + Mian_3_2(i, j, 0) + Mian_3_3(i, j, 0)) * MIAN_3_SCORE + Huo_2(i, j, 0) * HUO_2_SCORE + (Mian_2_1(i, j, 0) + Mian_2_2(i, j, 0)) * MIAN_2_SCORE;
				if (i >= 6 && i <= 8 && j >= 6 && j <= 8) {
					value[i][j]++;
				}
			}
		}
	}
}
