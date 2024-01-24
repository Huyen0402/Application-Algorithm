#include <bits/stdc++.h>

using namespace std;
 
#define N 100
 
int n, M;
int C[N][N];
bool visited[N];
int x[N];
int f;
int ans = 0;

void solution() {
	if(f + C[x[n]][x[1]] <= M) ans++;
}

bool check(int v, int k) {
	if(visited[v] == true) return false;
	if(f + C[x[k - 1]][v] > M) return false;
	return true; 
}

void Try(int k) {
	for(int v = 1; v <= n; v++) {
		if(check(v, k)) {
			x[k] = v;
			visited[v] = true;
			f = f + C[x[k - 1]][x[k]];
			if(k == n) solution();
			else {
				Try(k + 1);
			}
			visited[v] = false;
			f = f - C[x[k - 1]][x[k]];
		}
	}
}

int main() {
	f = 0;
	cin >> n >> M;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> C[i][j];
		}
	}
	
	for(int v = 1; v <= n; v++) {
		visited[v] = false;
	}
	
	x[1] = 1; visited[1] = true;
	Try(2);
	cout << ans;
	
	return 0;
}
