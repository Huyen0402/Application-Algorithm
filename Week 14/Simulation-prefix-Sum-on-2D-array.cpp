#include<bits/stdc++.h>

using namespace std;

#define N 1001

int n, m;
int a[N][N];
int S[N][N];
int Q;
int r1, r2, c1, c2;
int res = 0;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	
	S[0][0] = 0;
	S[0][1] = a[0][1];
	S[1][0] = a[1][0];
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
		}
	}
	
	cin >> Q;
	
	for(int q = 1; q <= Q; q++) {
		cin >> r1 >> c1 >> r2 >> c2;
		res = S[r2][c2] - S[r2][c1 - 1] - S[r1 - 1][c2] + S[r1 - 1][c1 - 1];
		cout << res << endl;
	}
	
	return 0;
}
