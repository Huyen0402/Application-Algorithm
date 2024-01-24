#include <bits/stdc++.h> 

using namespace std;
bool markR[9][10];
bool markC[9][10];
bool mark[3][3][10];
int x[9][9];
int res;

bool check(int v, int r, int c) {
	return markR[r][v] == false && markC[c][v] == false && mark[r/3][c/3][v] == false;
}

void solution() {
	res ++;
}

void Try(int r, int c) {
	if(x[r][c] > 0) {
		if(r == 8 && c == 8) solution();
		else {
			if(c == 8) Try(r + 1, 0);
			else Try(r, c + 1);
		}  
		return;
	}
	for(int v = 1; v <= 9; v++) {
		if(check(v, r, c)) {
			x[r][c] = v;
			markR[r][v] = true;
			markC[c][v] = true;
			mark[r/3][c/3][v] = true;
			if(r == 8 && c == 8) solution();
			else {
				if(c < 8) Try(r, c + 1);
				else Try(r + 1, 0);
			}
			markR[r][v] = false;
			markC[c][v] = false;
			mark[r/3][c/3][v] = false;
		x[r][c] = 0;
		}
	}
}

int main() {
	res = 0;
	
	for(int v = 1; v <= 9; v++) {
		for(int r = 0; r <= 8; r++) markR[r][v] = false;
		for(int c = 0; c <= 8; c++) markC[c][v] = false;
		for(int i = 0; i <= 2; i++) {
			for(int j = 0; j <= 2; j++) {
				mark[i][j][v] = false;			
			}
		}
	}
	
	for(int i = 0; i <= 8; i++) {
		for(int j = 0; j <= 8; j++) {
			cin >> x[i][j];
			if(x[i][j] > 0) {
				int v = x[i][j];
				markR[i][v] = true;
				markC[j][v] = true;
				mark[i/3][j/3][v] = true;
			}
		}
	}
	
	Try(0, 0);
	cout << res << endl;
	
	return 0;
}
