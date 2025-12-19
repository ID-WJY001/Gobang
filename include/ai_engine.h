#pragma once
#include "game_state.h"

// Constants
const int CHENG_5_SCORE = 5000000;
const int HUO_4_SCORE = 100000;
const int CHONG_4_SCORE = 10000;
const int DAN_HUO_3_SCORE = 8000;
const int TIAO_HUO_3_SCORE = 7000;
const int MIAN_3_SCORE = 500;
const int HUO_2_SCORE = 50;
const int MIAN_2_SCORE = 10;

// Evaluation Functions
int Cheng_5(int i, int j, int k);
int Huo_4(int i, int j, int k);
int Dan_Huo_3(int i, int j, int k);
int Tiao_Huo_3(int i, int j, int k);
int Huo_2(int i, int j, int k);
int Chong_4_1(int i, int j, int k);
int Chong_4_2(int i, int j, int k);
int Mian_3_1(int i, int j, int k);
int Mian_3_2(int i, int j, int k);
int Mian_3_3(int i, int j, int k);
int Mian_2_1(int i, int j, int k);
int Mian_2_2(int i, int j, int k);

// AI Functions
void CalculateValuesWhite();
void CalculateValuesBlack();
node GetBestMove(bool isBlack);
node min_max_alpha_beta(int vis[15][15], int depth, int alpha, int beta, bool maximizing_player);
