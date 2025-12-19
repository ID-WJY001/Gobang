#include "../include/game_rules.h"
#include "../include/game_state.h"

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
		if (vis[i + ii][j] != 2) {//���ǰ���
			if (i + ii >= 15 || vis[i + ii][j] != 1) {//���Ǻ���
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
bool IsForbiddenAt(int i, int j) {
	if (Long_Connect(i, j)) return true;
	if (Three_Three(i, j)) return true;
	if (Four_Four(i, j)) return true;
	return false;
}

