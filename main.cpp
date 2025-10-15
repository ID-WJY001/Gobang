/*开发日志  
* 开发项目：五子棋
* 开发人员：王俊阳
* 开发时间：2024.11.20-2024.12.24
*/
#include<graphics.h>
#include<mmsystem.h>
#include<iostream>
#include<iomanip>
#pragma comment(lib,"winmm.lib")
using namespace std;
struct node {
	int x;
	int y;
	int value;
};
void Load_UI();
void Start_UI();
void Main_Page();
void New_Game();
void Load_Game();
void Settings();
void Exit();
void Save_Game();
void Choose_Color();
void Human_Computer();       
void Human_Human();
void Music();
void Chess_Position();
void Rule_Page();
void Details_Page();
void Forbidden_Move();
void AI_Play_Black();
void AI_Play_White();
void Black_Win();
void White_Win();
void Tie();
bool Judge_Win(int i,int j);
bool Long_Connect(int i,int j);
bool Three_Three(int i,int j);
bool Four_Four(int i,int j);
bool Judge_Forbidden_Move(int i,int j);
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
node min_max_alpha_beta(int vis[15][15], int depth, int alpha, int beta, bool maximizing_player);
IMAGE mainpage,inipage,page,pagemini;
IMAGE black, white;
IMAGE chessboard;
IMAGE startgame;
IMAGE loadgame;
IMAGE savegame;
IMAGE settings;
IMAGE quitgame;
IMAGE back;
IMAGE mask,maskplus,blackmask,whitemask;
IMAGE humancomputer, humanhuman;
IMAGE musicon, musicoff, gamerules, aboutgame;
IMAGE blackplay, whiteplay;
IMAGE blackplayplus, whiteplayplus;
IMAGE clicktostart;    
const int CHENG_5_SCORE = 5000000;
const int HUO_4_SCORE = 100000;
const int CHONG_4_SCORE = 10000;
const int DAN_HUO_3_SCORE = 8000;
const int TIAO_HUO_3_SCORE = 7000;
const int MIAN_3_SCORE = 500;
const int HUO_2_SCORE = 50;
const int MIAN_2_SCORE = 10;
const int black_playing = 1, white_playing = 0;
bool color,playercolor,aicolor; 
bool flag_color;
bool flag_exit = 0;
bool flag_music = 1;
bool flag_pause = 0;
bool flag_save = 0;
bool flag_com = 0;
int pos[15][15][2];
int vis[15][15];
int value[15][15];
void Load_UI() {
	loadimage(&mainpage,"mainpage.jpg");
	loadimage(&inipage, "inipage.jpg");
	loadimage(&chessboard, "chessboard.jpg");
	loadimage(&startgame,"startgame.jpg");
	loadimage(&loadgame, "loadgame.jpg");
	loadimage(&savegame, "savegame.jpg");
	loadimage(&quitgame, "quitgame.jpg");
	loadimage(&settings, "settings.jpg");
	loadimage(&mask, "mask.jpg");
	loadimage(&blackmask, "blackmask.jpg"); 
	loadimage(&whitemask, "whitemask.jpg");
	loadimage(&humancomputer, "humancomputer.jpg");
	loadimage(&humanhuman, "humanhuman.jpg");
	loadimage(&maskplus, "maskplus.jpg");
	loadimage(&back, "back.jpg");
	loadimage(&musicon, "musicon.jpg");
	loadimage(&musicoff, "musicoff.jpg");
	loadimage(&gamerules, "gamerules.jpg");
	loadimage(&aboutgame, "aboutgame.jpg");
	loadimage(&black, "black.jpg");
	loadimage(&white, "white.jpg");
	loadimage(&blackplay, "blackplay.jpg");
	loadimage(&whiteplay, "whiteplay.jpg");
	loadimage(&blackplayplus, "blackplayplus.jpg");
	loadimage(&whiteplayplus, "whiteplayplus.jpg");
	loadimage(&page, "page.jpg");
	loadimage(&pagemini, "pagemini.jpg");
	loadimage(&clicktostart, "clicktostart.jpg");
}
void Start_UI() {
	putimage(0,0,&mainpage);
	putimage(347, 700, &mask, NOTSRCERASE);
	putimage(347, 700, &startgame,SRCINVERT);
	putimage(517, 700, &mask, NOTSRCERASE);
	putimage(517, 700, &loadgame, SRCINVERT);
	putimage(347, 790, &mask, NOTSRCERASE);
	putimage(347, 790, &settings, SRCINVERT);
	putimage(517, 790, &mask, NOTSRCERASE);
	putimage(517, 790, &quitgame, SRCINVERT);
	settextcolor(RGB(240, 100, 0));
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 120;
	_tcscpy_s(f.lfFaceName, _T("隶书"));
	f.lfQuality = ANTIALIASED_QUALITY;//抗锯齿效果
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(452, 200, "五");
	outtextxy(452, 320, "子");
	outtextxy(452, 440, "棋");
}
void Main_Page() {
	bool flag = 0;
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 347 && msg.x < 672 && msg.y > 700 && msg.y < 871) {
					flag = 1;
				}
			}
			else if (msg.message == WM_LBUTTONUP && flag) {
				if (msg.x > 347 && msg.x < 507 && msg.y > 700 && msg.y < 781) {//New Game
					Sleep(100);
					New_Game();
					return;
				}
				if (msg.x > 512 && msg.x < 672 && msg.y > 700 && msg.y < 781) {//Load Game
					Sleep(100);
					Load_Game();
					return;
				}
				if (msg.x > 347 && msg.x < 507 && msg.y > 790 && msg.y < 871) {//Settings
					Sleep(100);
					putimage(0, 0, &mainpage);
					putimage(432, 610, &mask, NOTSRCERASE);
					if (flag_music) {
						putimage(432, 610, &musicon, SRCINVERT);
					}
					else {
						putimage(432, 610, &musicoff, SRCINVERT);
					}
					Settings();
					return;
				}
				if (msg.x > 512 && msg.x < 672 && msg.y > 790 && msg.y < 871) {//Exit（直接退出）
					Sleep(100);
					flag_exit = 1;
					return;
				}
			}
		}
	}
}
void New_Game() {
	putimage(0, 0, &mainpage);
	putimage(212, 740, &maskplus, NOTSRCERASE);
	putimage(212, 740, &humancomputer, SRCINVERT);
	putimage(532, 740, &maskplus, NOTSRCERASE);
	putimage(532, 740, &humanhuman, SRCINVERT);
	putimage(50, 50, &mask, NOTSRCERASE);
	putimage(50, 50, &back, SRCINVERT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 80;
	_tcscpy_s(f.lfFaceName, _T("隶书"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(472, 100, "请");
	outtextxy(472, 180, "选");
	outtextxy(472, 260, "择");
	outtextxy(472, 340, "游");
	outtextxy(472, 420, "戏");
	outtextxy(472, 500, "模");
	outtextxy(472, 580, "式");
	bool flag = 0;
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {
					flag = 1;
				}
				if (msg.x > 212 && msg.x < 492 && msg.y > 740 && msg.y < 882) {
					flag = 1;
				}
				if (msg.x > 532 && msg.x < 812 && msg.y > 740 && msg.y < 882) {
					flag = 1;
				}
			}
			else if (msg.message == WM_LBUTTONUP && flag) {
				if (msg.x > 212 && msg.x < 492 && msg.y > 740 && msg.y < 882) {//Human-Computer
					Sleep(100);
					flag_com = 1;
					Choose_Color();
					return;
				}
				if (msg.x > 532 && msg.x < 812 && msg.y > 740 && msg.y < 882) {//Human-Human
					mciSendString("close BGM", 0, 0, 0);
					Sleep(500);
					memset(vis, 0, sizeof(vis));
					flag_com = 0;
					Human_Human();
					return;
				}
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {//Back
					Sleep(100);
					Start_UI();
					Main_Page();
					return;
				}
			}
		}
	}
}
void Choose_Color() {
	putimage(0, 0, &mainpage);
	putimage(212, 740, &maskplus, NOTSRCERASE);
	putimage(212, 740, &blackplayplus, SRCINVERT);
	putimage(532, 740, &maskplus, NOTSRCERASE);
	putimage(532, 740, &whiteplayplus, SRCINVERT);
	putimage(50, 50, &mask, NOTSRCERASE);
	putimage(50, 50, &back, SRCINVERT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 80;
	_tcscpy_s(f.lfFaceName, _T("隶书"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(472, 100, "请");
	outtextxy(472, 180, "选");
	outtextxy(472, 260, "择");
	outtextxy(472, 340, "执");
	outtextxy(472, 420, "棋");
	outtextxy(472, 500, "颜");
	outtextxy(472, 580, "色");
	bool flag = 0;
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {
					flag = 1;
				}
				if (msg.x > 212 && msg.x < 492 && msg.y > 740 && msg.y < 882) {
					flag = 1;
				}
				if (msg.x > 532 && msg.x < 812 && msg.y > 740 && msg.y < 882) {
					flag = 1;
				}
			}
			else if (msg.message == WM_LBUTTONUP && flag) {
				if (msg.x > 212 && msg.x < 492 && msg.y > 740 && msg.y < 882) {
					Sleep(500);
					playercolor = 1;
					aicolor = 0;
					memset(vis, 0, sizeof(vis));
					memset(value, 0, sizeof(value));
					Human_Computer();
					return;
				}
				if (msg.x > 532 && msg.x < 812 && msg.y > 740 && msg.y < 882) {
					Sleep(500);
					playercolor = 0;
					aicolor = 1;
					memset(vis, 0, sizeof(vis));
					memset(value, 0, sizeof(value));
					Human_Computer();
					return;
				}
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {
					Sleep(100);
					New_Game();
					return;
				}
			}
		}
	}
}
void Settings() {
	putimage(50, 50, &mask, NOTSRCERASE);
	putimage(50, 50, &back, SRCINVERT);
	putimage(432, 700, &mask, NOTSRCERASE);
	putimage(432, 700, &gamerules, SRCINVERT);
	putimage(432, 790, &mask, NOTSRCERASE);
	putimage(432, 790, &aboutgame, SRCINVERT);
	bool flag = 0;
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {
					flag = 1;
				}
				if (msg.x > 432 && msg.x < 592 && msg.y > 610 && msg.y < 871) {
					flag = 1;
				}
			}
			else if (msg.message == WM_LBUTTONUP && flag) {
				if (msg.x > 432 && msg.x < 592 && msg.y > 610 && msg.y < 691) {//Music On/Off ;
					Sleep(100);
					flag_music = !flag_music;
					Music();
					return;
				}
				if (msg.x > 432 && msg.x < 592 && msg.y > 700 && msg.y < 781) {//Rules
					Sleep(100);
					Rule_Page();
					return;
				}
				if (msg.x > 432 && msg.x < 592 && msg.y > 790 && msg.y < 871) {//Details
					Sleep(100);
					Details_Page();
					return;
				}
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {//Back
					Sleep(100);
					Start_UI();
					Main_Page();
					return;
				}
			}
		}
	}
}
void Rule_Page() {
	putimage(50, 50, &mask, NOTSRCERASE);
	putimage(50, 50, &back, SRCINVERT);
	putimage(240, 150, &page);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 50;
	_tcscpy_s(f.lfFaceName, _T("隶书"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(400, 170, "游戏规则");
	f.lfHeight = 30;
	settextstyle(&f);
	outtextxy(260, 235, "1.黑白双方轮流落子，黑方为先手。");
	outtextxy(260, 275, "2.在横、竖、斜方向上连成五子（连");
	outtextxy(290, 315, "续五个棋子皆为己方）者为胜。");
	outtextxy(260, 355, "3.黑棋在行棋过程中，如果违反以下");
	outtextxy(290, 395, "“禁手规则”会被判负：");
	f.lfHeight = 25;
	settextstyle(&f);
	outtextxy(280, 435, "（1）三三禁手：黑棋在一个位置下子后，");
	outtextxy(330, 465, "形成两个或两个以上的活三。活三是");
	outtextxy(330, 495, "指在棋盘上有三个连续的黑子，且两");
	outtextxy(330, 525, "端都有空位可以继续下子形成五连。");
	outtextxy(280, 555, "（2）四四禁手：黑棋在一个位置下子后，");
	outtextxy(330, 585, "形成两个或两个以上的活四。活四是");
	outtextxy(330, 615, "指在棋盘上有四个连续的黑子，且有"); 
	outtextxy(330, 645, "空位可以继续下子形成五连。"); 
	outtextxy(280, 675, "（3）长连禁手：黑棋在一个位置下子后，");
	outtextxy(330, 705, "形成六个或更多连续的黑子。"); 
	outtextxy(280, 735, "（4）四三禁手：黑棋在一个位置下子后，"); 
	outtextxy(330, 765, "同时形成一个活四和一个活三。这种");
	outtextxy(330, 795, "情况也被视为禁手。");
	bool flag = 0;
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {
					flag = 1;
				}
			}
			else if (msg.message == WM_LBUTTONUP && flag) {
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {//Back
					Sleep(100);
					Start_UI(); 
					putimage(0, 0, &mainpage);
					putimage(432, 610, &mask, NOTSRCERASE);
					if (flag_music) {
						putimage(432, 610, &musicon, SRCINVERT);
					}
					else {
						putimage(432, 610, &musicoff, SRCINVERT);
					}
					Settings();
					return;
				}
			}
		}
	}
}
void Details_Page() {
	putimage(50, 50, &mask, NOTSRCERASE);
	putimage(50, 50, &back, SRCINVERT);
	putimage(240, 500, &pagemini);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 50;
	_tcscpy_s(f.lfFaceName, _T("隶书"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(400, 525, "游戏说明");
	f.lfHeight = 30;
	settextstyle(&f);
	outtextxy(260, 605, "开发人员：王俊阳");
	outtextxy(260, 655, "开发项目：五子棋");
	outtextxy(260, 705, "背景音乐：Flower Dance");
	outtextxy(260, 755, "开发时间：2024.11.20-2024.12.24");
	bool flag = 0;
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {
					flag = 1;
				}
			}
			else if (msg.message == WM_LBUTTONUP && flag) {
				if (msg.x > 50 && msg.x < 210 && msg.y > 50 && msg.y < 131) {
					Sleep(100);
					Start_UI();
					putimage(0, 0, &mainpage);
					putimage(432, 610, &mask, NOTSRCERASE);
					if (flag_music) {
						putimage(432, 610, &musicon, SRCINVERT);
					}
					else {
						putimage(432, 610, &musicoff, SRCINVERT);
					}
					Settings();
					return;
				}
			}
		}
	}
}
void Music() {
	if (flag_music) {
		mciSendString("open bgmusic.mp3", NULL, 0, NULL);
		mciSendString("play bgmusic.mp3 repeat", NULL, 0, NULL);
		putimage(0, 0, &mainpage);
		putimage(432, 610, &mask, NOTSRCERASE);
		putimage(432, 610, &musicon, SRCINVERT);
		Settings();
	}
	if (!flag_music) {
		mciSendString("close bgmusic.mp3", NULL, 0, NULL);
		putimage(0, 0, &mainpage);
		putimage(432, 610, &mask, NOTSRCERASE);
		putimage(432, 610, &musicoff, SRCINVERT);
		Settings();
	}
}
void Human_Computer() {
	int flagwhite = 1;
	putimage(0, 0, &inipage);
	putimage(162, 162, &chessboard);
	putimage(200, 50, &mask, NOTSRCERASE);
	putimage(200, 50, &savegame, SRCINVERT);
	putimage(432, 50, &mask, NOTSRCERASE);
	putimage(432, 50, &blackplay, SRCINVERT);
	putimage(664, 50, &mask, NOTSRCERASE);
	putimage(664, 50, &quitgame, SRCINVERT);
	color = 1;
	if (flagwhite && color != playercolor) {
		putimage(432, 50, &mask, NOTSRCERASE);
		putimage(432, 50, &whiteplay, SRCINVERT);
		color = !color;
		flagwhite = 0;
		srand(time(0));
		int ranx = rand() % 3 + 6;
		int rany = rand() % 3 + 6;
		vis[ranx][rany] = 1;
		putimage(pos[ranx][rany][0], pos[ranx][rany][1], &blackmask, NOTSRCERASE);
		putimage(pos[ranx][rany][0], pos[ranx][rany][1], &black, SRCINVERT);
	}
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 200 && msg.x < 360 && msg.y > 50 && msg.y < 131) {
					Sleep(100);
					Save_Game();
					return;
				}
				if (msg.x > 664 && msg.x < 824 && msg.y > 50 && msg.y < 131) {
					Sleep(100);
					Exit();
					return;
				}
				for (int i = 0; i < 15; i++) {
					for (int j = 0; j < 15; j++) {
						if (msg.x >= pos[i][j][0] && msg.x <= pos[i][j][0] + 45 && msg.y >= pos[i][j][1] && msg.y <= pos[i][j][1] + 43) {
							if (!vis[i][j]) {
								if (color == playercolor) {
									if (color == black_playing) {
										putimage(pos[i][j][0], pos[i][j][1], &blackmask, NOTSRCERASE);
										putimage(pos[i][j][0], pos[i][j][1], &black, SRCINVERT);
										vis[i][j] = 1;
										if (Long_Connect(i, j)) {
											Forbidden_Move();
											return;
										}
										else if (Judge_Win(i, j)) {
											Black_Win();
											return;
										}
										else if (Judge_Forbidden_Move(i, j)) {
											Forbidden_Move();
											return;
										}
										else {
											putimage(432, 50, &mask, NOTSRCERASE);
											putimage(432, 50, &whiteplay, SRCINVERT);
											color = !color;
											AI_Play_White();
										}
									}
									else {
										putimage(pos[i][j][0], pos[i][j][1], &whitemask, NOTSRCERASE);
										putimage(pos[i][j][0], pos[i][j][1], &white, SRCINVERT);
										vis[i][j] = 2;
										if (Judge_Win(i, j)) {
											White_Win();
											return;
										}
										else {
											putimage(432, 50, &mask, NOTSRCERASE);
											putimage(432, 50, &blackplay, SRCINVERT);
											color = !color;
											AI_Play_Black();
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void Human_Human() {
	color = black_playing;
	putimage(0, 0, &inipage);
	putimage(162, 162, &chessboard);
	putimage(200, 50, &mask, NOTSRCERASE);
	putimage(200, 50, &savegame, SRCINVERT);
	putimage(432, 50, &mask, NOTSRCERASE);
	putimage(432, 50, &blackplay, SRCINVERT);
	putimage(664, 50, &mask, NOTSRCERASE);
	putimage(664, 50, &quitgame, SRCINVERT);
	color = 1;
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 200 && msg.x < 360 && msg.y > 50 && msg.y < 131) {
					Sleep(100);
					Save_Game();
					return;
				}
				if (msg.x > 664 && msg.x < 824 && msg.y > 50 && msg.y < 131) {
					Sleep(100);
					Exit();
					return;
				}
				for (int i = 0; i < 15; i++) {
					for (int j = 0; j < 15; j++) {
						if (msg.x >= pos[i][j][0] && msg.x <= pos[i][j][0] + 45 && msg.y >= pos[i][j][1] && msg.y <= pos[i][j][1] + 43) {
							if (!vis[i][j]) {
								if (color == black_playing) {
									Sleep(50);
									putimage(pos[i][j][0], pos[i][j][1], &blackmask, NOTSRCERASE);
									putimage(pos[i][j][0], pos[i][j][1], &black, SRCINVERT);
									vis[i][j] = 1;
									if (Long_Connect(i, j)) {
										Forbidden_Move();
										return;
									}
									else if (Judge_Win(i, j)) {
										Black_Win();
										return;
									}
									else if (Judge_Forbidden_Move(i, j)) {
										Forbidden_Move();
										return;
									}
									else {
										putimage(432, 50, &mask, NOTSRCERASE);
										putimage(432, 50, &whiteplay, SRCINVERT);
									}
								}
								else {
									Sleep(50);
									putimage(pos[i][j][0], pos[i][j][1], &whitemask, NOTSRCERASE);
									putimage(pos[i][j][0], pos[i][j][1], &white, SRCINVERT);
									vis[i][j] = 2;
									if (Judge_Win(i,j)) {
										White_Win();
										return;
									}
									else {
										putimage(432, 50, &mask, NOTSRCERASE);
										putimage(432, 50, &blackplay, SRCINVERT);
									}
								}
								color = ! color;
							}
						}
					}
				}
			}
		}
	}
}
void Exit() {
	Sleep(100);
	Start_UI();
	Main_Page();
	memset(vis, 0, sizeof(vis));
	return;
}
void Chess_Position() {
	int x, y;
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++) {
			x = 155 + i * 48; y = 155 + j * 48;
			pos[i][j][0] = x;
			pos[i][j][1] = y;
		}
	}
}
void Save_Game() {
	flag_save = 1;
	Sleep(100);
	Start_UI();
	Main_Page();
	flag_color = color;
	return;
}
void Load_Game() {
	if (flag_save) {
		flag_save = 0;
		putimage(0, 0, &inipage);
		putimage(162, 162, &chessboard);
		putimage(200, 50, &mask, NOTSRCERASE);
		putimage(200, 50, &savegame, SRCINVERT);
		putimage(664, 50, &mask, NOTSRCERASE);
		putimage(664, 50, &quitgame, SRCINVERT);
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (vis[i][j] == 1) {
					putimage(pos[i][j][0], pos[i][j][1], &blackmask, NOTSRCERASE);
					putimage(pos[i][j][0], pos[i][j][1], &black, SRCINVERT);
				}
				if (vis[i][j] == 2) {
					putimage(pos[i][j][0], pos[i][j][1], &whitemask, NOTSRCERASE);
					putimage(pos[i][j][0], pos[i][j][1], &white, SRCINVERT);
				}
			}
		}
		if (flag_color) {
			putimage(432, 50, &mask, NOTSRCERASE);
			putimage(432, 50, &blackplay, SRCINVERT);
		}
		else {
			putimage(432, 50, &mask, NOTSRCERASE);
			putimage(432, 50, &whiteplay, SRCINVERT);
		}
		ExMessage msg;
		if (!flag_com) {
			while (1) {
				if (peekmessage(&msg)) {
					if (msg.message == WM_LBUTTONDOWN) {
						if (msg.x > 200 && msg.x < 360 && msg.y > 50 && msg.y < 131) {
							Sleep(100);
							Save_Game();
							return;
						}
						if (msg.x > 664 && msg.x < 824 && msg.y > 50 && msg.y < 131) {
							Sleep(100);
							Exit();
							return;
						}
						for (int i = 0; i < 15; i++) {
							for (int j = 0; j < 15; j++) {
								if (msg.x >= pos[i][j][0] && msg.x <= pos[i][j][0] + 45 && msg.y >= pos[i][j][1] && msg.y <= pos[i][j][1] + 43) {
									if (!vis[i][j]) {
										if (color == black_playing) {
											Sleep(50);
											putimage(pos[i][j][0], pos[i][j][1], &blackmask, NOTSRCERASE);
											putimage(pos[i][j][0], pos[i][j][1], &black, SRCINVERT);
											vis[i][j] = 1;
											if (Long_Connect(i, j)) {
												Forbidden_Move();
												return;
											}
											else if (Judge_Win(i, j)) {
												Black_Win();
												return;
											}
											else if (Judge_Forbidden_Move(i, j)) {
												Forbidden_Move();
												return;
											}
											else {
												putimage(432, 50, &mask, NOTSRCERASE);
												putimage(432, 50, &whiteplay, SRCINVERT);
											}
										}
										else {
											Sleep(50);
											putimage(pos[i][j][0], pos[i][j][1], &whitemask, NOTSRCERASE);
											putimage(pos[i][j][0], pos[i][j][1], &white, SRCINVERT);
											vis[i][j] = 2;
											if (Judge_Win(i, j)) {
												White_Win();
												return;
											}
											else {
												putimage(432, 50, &mask, NOTSRCERASE);
												putimage(432, 50, &blackplay, SRCINVERT);
											}
										}
										color = !color;
									}
								}
							}
						}
					}
				}
			}
		}
		else {
			while (1) {
				if (peekmessage(&msg)) {
					if (msg.message == WM_LBUTTONDOWN) {
						if (msg.x > 200 && msg.x < 360 && msg.y > 50 && msg.y < 131) {
							Sleep(100);
							Save_Game();
							return;
						}
						if (msg.x > 664 && msg.x < 824 && msg.y > 50 && msg.y < 131) {
							Sleep(100);
							Exit();
							return;
						}
						for (int i = 0; i < 15; i++) {
							for (int j = 0; j < 15; j++) {
								if (msg.x >= pos[i][j][0] && msg.x <= pos[i][j][0] + 45 && msg.y >= pos[i][j][1] && msg.y <= pos[i][j][1] + 43) {
									if (!vis[i][j]) {
										if (color == playercolor) {
											if (color == black_playing) {
												putimage(pos[i][j][0], pos[i][j][1], &blackmask, NOTSRCERASE);
												putimage(pos[i][j][0], pos[i][j][1], &black, SRCINVERT);
												vis[i][j] = 1;
												if (Long_Connect(i, j)) {
													Forbidden_Move();
													return;
												}
												else if (Judge_Win(i, j)) {
													Black_Win();
													return;
												}
												else if (Judge_Forbidden_Move(i, j)) {
													Forbidden_Move();
													return;
												}
												else {
													putimage(432, 50, &mask, NOTSRCERASE);
													putimage(432, 50, &whiteplay, SRCINVERT);
													color = !color;
													AI_Play_White();
												}
											}
											else {
												putimage(pos[i][j][0], pos[i][j][1], &whitemask, NOTSRCERASE);
												putimage(pos[i][j][0], pos[i][j][1], &white, SRCINVERT);
												vis[i][j] = 2;
												if (Judge_Win(i, j)) {
													White_Win();
													return;
												}
												else {
													putimage(432, 50, &mask, NOTSRCERASE);
													putimage(432, 50, &blackplay, SRCINVERT);
													color = !color;
													AI_Play_Black();
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else {
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 50;
		_tcscpy_s(f.lfFaceName, _T("隶书"));
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		setbkmode(TRANSPARENT);
		outtextxy(330, 600, "请先开始新游戏！");
		Sleep(1000);
		Start_UI();
		Main_Page();
		return;
	}
}
bool Long_Connect(int i, int j) {
	int flag1 = 0, flag2 = 0;
	for (int ii = 1; ii <= 15; ii++) {
		if (i + ii >= 15 || vis[i + ii][j] != 1) {
			flag1 = ii - 1;
			break;
		}
	}
	for (int ii = 1; ii <= 15; ii++) {
		if (i - ii < 0 || vis[i - ii][j] != 1) {
			flag2 = ii - 1;
			break;
		}
	}
	if (flag1 + flag2 >= 5) {
		return 1;
	}
	for (int jj = 1; jj <= 15; jj++) {
		if (j + jj >= 15 || vis[i][j + jj] != 1) {
			flag1 = jj - 1;
			break;
		}
	}
	for (int jj = 1; jj <= 15; jj++) {
		if (j - jj < 0 || vis[i][j - jj] != 1) {
			flag2 = jj - 1;
			break;
		}
	}
	if (flag1 + flag2 >= 5) {
		return 1;
	}
	for (int ij = 1; ij <= 15; ij++) {
		if (i + ij >= 15 || j - ij < 0 || vis[i + ij][j - ij] != 1) {
			flag1 = ij - 1;
			break;
		}
	}
	for (int ij = 1; ij <= 15; ij++) {
		if (i - ij < 0 || j + ij >= 15 || vis[i - ij][j + ij] != 1) {
			flag2 = ij - 1;
			break;
		}
	}
	if (flag1 + flag2 >= 5) {
		return 1;
	}
	for (int ji = 1; ji <= 15; ji++) {
		if (i + ji >= 15 || j + ji >= 15 || vis[i + ji][j + ji] != 1) {
			flag1 = ji - 1;
			break;
		}
	}
	for (int ji = 1; ji <= 15; ji++) {
		if (j - ji < 0 || i - ji < 0 || vis[i - ji][j - ji] != 1) {
			flag2 = ji - 1;
			break;
		}
	}
	if (flag1 + flag2 >= 5) {
		return 1;
	}
	return 0;
}
bool Three_Three(int i, int j) {
	int cnt = 0;
	int flag1 = 0, flag2 = 0;
	for (int ii = 1; ii <= 5; ii++) {
		if (vis[i + ii][j] != 2) {//不是白棋
			if (i + ii >= 15 || vis[i + ii][j] != 1) {//不是黑棋
			flag1 = ii - 1;
			break;
			}
		}
		else {
			break;
		}
	}
	for (int ii = 1; ii <= 5; ii++) {
		if (vis[i - ii][j] != 2) {
			if (i - ii < 0 || vis[i - ii][j] != 1) {
				flag2 = ii - 1;
				break;
			}
		}
		else {
			break;
		}
	}
	if (flag1 + flag2 == 2) {
		cnt++;
	}
	flag1 = 0;
	flag2 = 0;
	for (int jj = 1; jj <= 5; jj++) {
		if (vis[i][j + jj] != 2) {
			if (j + jj >= 15 || vis[i][j + jj] != 1) {
				flag1 = jj - 1;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int jj = 1; jj <= 5; jj++) {
		if (vis[i][j - jj] != 2) {
			if (j - jj < 0 || vis[i][j - jj] != 1) {
				flag2 = jj - 1;
				break;
			}
		}
		else {
			break;
		}
	}
	if (flag1 + flag2 == 2) {
		cnt++;
	}
	flag1 = 0;
	flag2 = 0;
	for (int ij = 1; ij <= 5; ij++) {
		if (vis[i + ij][j - ij] != 2) {
			if (i + ij >= 15 || j - ij < 0 || vis[i + ij][j - ij] != 1) {
				flag1 = ij - 1;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int ij = 1; ij <= 5; ij++) {
		if (vis[i - ij][j + ij] != 2) {
			if (i - ij < 0 || j + ij >= 15 || vis[i - ij][j + ij] != 1) {
				flag2 = ij - 1;
				break;
			}
		}
		else {
			break;
		}
	}
	if (flag1 + flag2 == 2) {
		cnt++;
	}
	flag1 = 0;
	flag2 = 0;
	for (int ji = 1; ji <= 5; ji++) {
		if(vis[i + ji][j + ji] != 2){
			if (i + ji >= 15 || j + ji >= 15 || vis[i + ji][j + ji] != 1) {
				flag1 = ji - 1;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int ji = 1; ji <= 5; ji++) {
		if (vis[i - ji][j - ji] != 2){
			if (j - ji < 0 || i - ji < 0 || vis[i - ji][j - ji] != 1) {
				flag2 = ji - 1;
				break;
			}
		}
		else {
			break;
		}
	}
	if (flag1 + flag2 == 2) {
		cnt++;
	}
	if (cnt >= 2) {
		return 1;
	}
	return 0;
}
bool Four_Four(int i, int j) {
	int cnt = 0;
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
	for (int ii = 1; ii <= 5; ii++) {
		if (vis[i + ii][j] != 0) {
			if ((i + ii >= 15 || vis[i + ii][j] != 1)&&vis[i+ii+1]) {
				flag1 = ii - 1;
				break;
			}
		}
		else {
			flag1 = ii - 1;
			break;
		}
	}
	for (int ii = 1; ii <= 5; ii++) {
		if (i + ii >= 15 || vis[i + ii][j] != 1) {
			flag3 = ii - 1;
			break;
		}
		else {
			flag3 = ii - 1;
			break;
		}
	}
	for (int ii = 1; ii <= 5; ii++) {
		if (vis[i - ii][j] != 0) {
			if (i - ii >= 15 || vis[i - ii][j] != 1) {
				flag2 = ii - 1;
				break;
			}
		}
		else {
			flag2 = ii - 1;
			break;
		}
	}
	for (int ii = 1; ii <= 5; ii++) {
		if (i - ii >= 15 || vis[i - ii][j] != 1) {
			flag4 = ii - 1;
			break;
		}
		else {
			flag4 = ii - 1;
			break;
		}
	}
	if (flag1 + flag2 == 3 && (flag3 < flag1 || flag4 < flag2)) {
		cnt++;
	}
	for (int jj = 1; jj <= 5; jj++) {
		if (j + jj >= 15 || vis[i][j + jj] != 1) {
			flag1 = jj - 1;
			break;
		}
		else {
			flag1 = jj - 1;
			break;
		}
	}
	for (int jj = 1; jj <= 5; jj++) {
		if (j - jj < 0 || vis[i][j - jj] != 1) {
			flag2 = jj - 1;
			break;
		}
		else {
			flag2 = jj - 1;
			break;
		}
	}
	if (flag1 + flag2 == 3) {
		cnt++;
	}
	for (int ij = 1; ij <= 5; ij++) {
		if (i + ij >= 15 || j - ij < 0 || vis[i + ij][j - ij] != 1) {
			flag1 = ij - 1;
			break;
		}
		else {
			flag1 = ij - 1;
			break;
		}
	}
	for (int ij = 1; ij <= 5; ij++) {
		if (i - ij < 0 || j + ij >= 15 || vis[i - ij][j + ij] != 1) {
			flag2 = ij - 1;
			break;
		}
		else {
			flag2 = ij - 1;
			break;
		}
	}
	if (flag1 + flag2 == 3) {
		cnt++;
	}
	for (int ji = 1; ji <= 5; ji++) {
		if (i + ji >= 15 || j + ji >= 15 || vis[i + ji][j + ji] != 1) {
			flag1 = ji - 1;
			break;
		}
		else {
			flag1 = ji - 1;
			break;
		}
	}
	for (int ji = 1; ji <= 5; ji++) {
		if (j - ji < 0 || i - ji < 0 || vis[i - ji][j - ji] != 1) {
			flag2 = ji - 1;
			break;
		}
		else {
			flag2 = ji - 1;
			break;
		}
	}
	if (flag1 + flag2 == 3) {
		cnt++;
	}
	if (cnt >= 2) {
		return 1;
	}
	return 0;
}
bool Judge_Forbidden_Move(int i, int j) {
	if (Long_Connect(i, j)) {
		return 1;
	}
	else if (Three_Three(i, j)) {
		return 1;
	}
	else if (Four_Four(i, j)) {
		return 1;
	}
	return 0;
}
void Forbidden_Move() {
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 80;
	_tcscpy_s(f.lfFaceName, _T("隶书"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(130, 875, "黑棋禁手，白棋胜利");
	putimage(200, 50, &mask, NOTSRCERASE);
	putimage(200, 50, &startgame, SRCINVERT);
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 200 && msg.x < 360 && msg.y > 50 && msg.y < 131) {
					Sleep(400);
					New_Game();
					return;
				}
				if (msg.x > 664 && msg.x < 824 && msg.y > 50 && msg.y < 131) {
					Sleep(200);
					Start_UI();
					Main_Page();
					return;
				}
			}
		}
	}
}
bool Judge_Win(int i,int j) {
	for (int ii = 0; ii < 5; ii++) {
		int flag = 1;
		for (int iii = 0; iii < 5; iii++) {
			if (!(i - ii + iii >= 0 && i - ii + iii < 15) || vis[i][j] != vis[i - ii + iii][j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return 1;
		}
	}
	for (int jj = 0; jj < 5; jj++) {
		int flag = 1;
		for (int jjj = 0; jjj < 5; jjj++) {
			if (!(j - jj + jjj >= 0 && j - jj + jjj < 15) || vis[i][j] != vis[i][j - jj + jjj]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return 1;
		}
	}
	for (int ij = 0; ij < 5; ij++) {
		int flag = 1;
		for (int ijj = 0; ijj < 5; ijj++) {
			if (!(i - ij + ijj >= 0 && i - ij + ijj < 15 && j - ij + ijj >= 0 && j - ij + ijj < 15) || vis[i][j] != vis[i - ij + ijj][j - ij + ijj] ) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return 1;
		}
	}
	for (int ji = 0; ji < 5; ji++) {
		int flag = 1;
		for (int jii = 0; jii < 5; jii++) {
			if (!(i - ji + jii >= 0 && i - ji + jii < 15 && j + ji - jii >= 0 && j + ji -jii < 15) || vis[i][j] != vis[i - ji + jii][j + ji - jii]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return 1;
		}
	}
	return 0;
}
void Black_Win() {
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 80;
	_tcscpy_s(f.lfFaceName, _T("隶书"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(350, 875, "黑棋胜利");
	putimage(200, 50, &mask, NOTSRCERASE);
	putimage(200, 50, &startgame, SRCINVERT);
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 200 && msg.x < 360 && msg.y > 50 && msg.y < 131) {
					Sleep(400);
					New_Game();
					return;
				}
				if (msg.x > 664 && msg.x < 824 && msg.y > 50 && msg.y < 131) {
					Sleep(200);
					Start_UI();
					Main_Page();
					return;
				}
			}
		}
	}
}
void White_Win() {
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 80;
	_tcscpy_s(f.lfFaceName, _T("隶书"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(350, 875, "白棋胜利");
	putimage(200, 50, &mask, NOTSRCERASE);
	putimage(200, 50, &startgame, SRCINVERT);
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 200 && msg.x < 360 && msg.y > 50 && msg.y < 131) {
					Sleep(400);
					New_Game();
					return;
				}
				if (msg.x > 664 && msg.x < 824 && msg.y > 50 && msg.y < 131) {
					Sleep(200);
					Start_UI();
					Main_Page();
					return;
				}
			}
		}
	}
}
void Tie() {
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 80;
	_tcscpy_s(f.lfFaceName, _T("隶书"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(350, 875, "黑白平局");
	putimage(200, 50, &mask, NOTSRCERASE);
	putimage(200, 50, &startgame, SRCINVERT);
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 200 && msg.x < 360 && msg.y > 50 && msg.y < 131) {
					Sleep(400);
					New_Game();
					return;
				}
				if (msg.x > 664 && msg.x < 824 && msg.y > 50 && msg.y < 131) {
					Sleep(200);
					Start_UI();
					Main_Page();
					return;
				}
			}
		}
	}
}
int Cheng_5(int i, int j, int k) {//11111
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
void AI_Play_Black() {
	int maxn = -1, i0, j0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (Judge_Forbidden_Move(i, j)) {
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
	int flagtie = 1;
	node down = min_max_alpha_beta(vis, 2, -100000000, 100000000, 1);
	i0 = down.x;
	j0 = down.y;
	flagtie = 0;
	if (flagtie) {
		Tie();
		return;
	}
	else {
		putimage(pos[i0][j0][0], pos[i0][j0][1], &blackmask, NOTSRCERASE);
		putimage(pos[i0][j0][0], pos[i0][j0][1], &black, SRCINVERT);
		vis[i0][j0] = 1;
		if (Judge_Win(i0, j0)) {
			Black_Win();
			return;
		}
		else {
			putimage(432, 50, &mask, NOTSRCERASE);
			putimage(432, 50, &whiteplay, SRCINVERT);
			color = !color;
			return;
		}
	}

}
void AI_Play_White() {
	int maxn = -1, i0, j0;
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
				value[i][j] += Huo_4(i, j, 0) * 500000 + (Chong_4_1(i, j, 0) + Chong_4_2(i, j, 0)) * CHONG_4_SCORE + Dan_Huo_3(i, j, 0) * DAN_HUO_3_SCORE + Tiao_Huo_3(i, j, 0) * 800 + (Mian_3_1(i, j, 0) + Mian_3_2(i, j, 0) + Mian_3_3(i, j, 0)) *  + Huo_2(i, j, 0) * HUO_2_SCORE + (Mian_2_1(i, j, 0) + Mian_2_2(i, j, 0)) * MIAN_2_SCORE;
				if (i >= 6 && i <= 8 && j >= 6 && j <= 8) {
					value[i][j]+=11;
				}
			}
		}
	}
	int flagtie = 1;
	node down = min_max_alpha_beta(vis, 2, -100000000, 100000000, 1);
	i0 = down.x;
	j0 = down.y;
	flagtie = 0;
	if (flagtie) {
		Tie();
		return;
	}
	else {
		putimage(pos[i0][j0][0], pos[i0][j0][1], &whitemask, NOTSRCERASE);
		putimage(pos[i0][j0][0], pos[i0][j0][1], &white, SRCINVERT);
		vis[i0][j0] = 2;
		if (Judge_Win(i0, j0)) {
			White_Win();
			return;
		}
		else {
			putimage(432, 50, &mask, NOTSRCERASE);
			putimage(432, 50, &blackplay, SRCINVERT);
			color = !color;
			return;
		}
	}
}
//alpha代表当前搜索路径上已找到的最大化玩家（试图使局面评估值最大的玩家）的最大可能评估值下限
//beta代表当前搜索路径上已找到的最小化玩家（试图使局面评估值最小的玩家，通常为对手）的最小可能评估值上限
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
					// 更新当前找到的最大评估值，取当前最大评估值和新得到的评估值中的较大者
					max_eval = max_node(max_eval, eval_score);
					// 更新alpha值，取当前最大评估值和已有alpha值中的较大者，作为新的alpha值，用于alpha-beta剪枝判断
					alpha = max(alpha, eval_score.value);
					// 进行alpha-beta剪枝判断，如果beta值小于等于alpha值，说明当前分支不可能再产生更优结果（对于最大化玩家来说，已经找到的最小化玩家的最小可能上限比当前找到的最大可能下限还小，后续搜索没必要进行了），直接跳出循环，停止对当前层剩余位置的搜索
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
					// 更新当前找到的最小评估值，取当前最小评估值和新得到的评估值中的较小者
					min_eval = min_node(min_eval, eval_score);
					// 更新beta值，取当前最小评估值和已有beta值中的较小者，作为新的beta值，用于alpha-beta剪枝判断
					beta = min(beta, eval_score.value);
					// 进行alpha-beta剪枝判断，如果beta值小于等于alpha值，说明当前分支不可能再产生更优结果（对于最小化玩家来说，已经找到的最大化玩家的最大可能下限比当前找到的最小可能上限还大，后续搜索没必要进行了），直接跳出循环，停止对当前层剩余位置的搜索
					if (beta <= alpha) {
						break;
					}
				}
			}
		}
		return min_eval;
	}
}
int main() {
	memset(value, 0, sizeof(value));
	initgraph(1024, 1024);
	mciSendString(_T("open bgmusic.mp3"), 0, 0, 0);
	mciSendString(_T("play bgmusic.mp3 repeat"), 0, 0, 0);
	Load_UI();
	Chess_Position();
	Start_UI();
	Main_Page();
	if (flag_exit) {
		return 0;
	}
	while(1);
	return 0;
}