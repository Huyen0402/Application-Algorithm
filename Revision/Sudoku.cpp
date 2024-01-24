#include<bits/stdc++.h>

using namespace std;

int x[9][9];
bool markR[9][10], markC[9][10], markS[9][9][10];
int cnt = 0;

bool check(int v, int r, int c) {
	if(markR[r][v]) return false;
	if(markC[c][v]) return false;
	if(markS[r/3][c/3][v]) return false;
	return true;
}

void solution() {
//	for(int i = 0; i < 9; i++) {
//		for(int j = 0; j < 9; j++) {
//			cout << x[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "--------------------------------" << endl;
	cnt ++;
}

void Try(int r, int c) {
	for(int v = 1; v <= 9; v++) {
		if(check(v, r, c)) {
			x[r][c] = v;
			markR[r][v] = true;
			markC[c][v] = true;
			markS[r/3][c/3][v] = true;
			if(r == 8 && c == 8) solution();
			else if(c == 8) Try(r + 1, 0);
			else Try(r, c + 1);
			markR[r][v] = false;
			markC[c][v] = false;
			markS[r/3][c/3][v] = false;
		}
	}
}

int main() {
	for(int v = 1; v <= 9; v++) {
		for(int r = 0; r < 9; r++) markR[r][v] = false;
		for(int c = 0; c < 9; c++) markC[c][v] = false;
		for(int i = 0; i <= 2; i++) {
			for(int j = 0; j <= 2; j++) {
				markS[i][j][v] = false;
			}
		}
	}
	
	Try(0, 0);
	cout << cnt;
	
	return 0;
}
