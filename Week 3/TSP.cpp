#include <bits/stdc++.h>

using namespace std;
 
#define N 100
 
int n;
int C[N][N];
bool visited[N];
int x[N];
int c_min;
int f;
int f_min;

void solution() {
	if(f + C[x[n]][x[1]] < f_min) {
		f_min = f + C[x[n]][x[1]];
	}
}

void Try(int k) {
	for(int v = 1; v <= n; v++) {
		if(visited[v] == false) {
			x[k] = v;
			visited[v] = true;
			f = f + C[x[k - 1]][x[k]];
			if(k == n) solution();
			else {
				if(f + (n - k + 1) * c_min < f_min) Try(k + 1);
			}
			visited[v] = false;
			f = f - C[x[k - 1]][x[k]];
		}
	}
}

int main() {
	f = 0;
	f_min = 1e9;
	c_min = 1e9;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> C[i][j];
			if(i != j && C[i][j] < c_min) {
				c_min = C[i][j];
			}
		}
	}
	
	for(int v = 1; v <= n; v++) {
		visited[v] = false;
	}
	
	x[1] = 1; visited[1] = true;
	Try(2);
	cout << f_min;
	
	return 0;
}
