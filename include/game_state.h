#pragma once

struct node {
	int x;
	int y;
	int value;
};

extern int vis[15][15];
extern int value[15][15];
extern bool color; // 1=Black, 0=White
