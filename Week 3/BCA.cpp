#include <bits/stdc++.h>

using namespace std;

#define N 50

int m, n;
vector<int> T[N];
bool conflict[N][N];
int res;
int x[N], load[N];

void input() {
	cin >> m >> n;
	for(int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int c;
			cin >> c;
			T[c].push_back(i);
		}
	}
	
	int K;
	cin >> K;
	for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            conflict[i][j] = false;

	for(int i = 1; i <= K; i++) {
		int a, b;
		cin >> a >> b;
		conflict[a][b] = true;
		conflict[b][a] = true;
	}
}

bool check(int v, int k) {
	for(int i = 0; i < k - 1; i++) {
		if(conflict[i][k] && x[i] == v) {
			return false;
		}
	}
	return true;
}

void solution() {
	int maxLoad = 0;
	for(int i = 1; i <= m; i++) {
		maxLoad = max(maxLoad, load[i]);
	}
	if(maxLoad < res) res= maxLoad;
}

void Try(int k) {
	for(int i = 0; i < T[k].size(); i++) {
		int v = T[k][i];
		if(check(v, k)) {
			x[k] = v;
			load[v]++;
			if(k == n) solution();
			else Try(k + 1);
			load[v]--;
		}
	}
}

int main() {
	input();
	
	for(int t = 1; t <= m; t++) load[t] = 0;
    res = 1e9;
    Try(1);
    cout << res;
	
	return 0;
}
