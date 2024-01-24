#include<bits/stdc++.h>

using namespace std;

#define N 1001
const int INF = 1e9;

int c[N][N], d[N][N];
int n, m;

void input() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			c[i][j] = INF;
		}
		c[i][i] = 0;
	}
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		c[u][v] = w;
	}
}

void FloydWarshall() {
	//INIT
	for(int u = 1; u <= n; u++) {
			for(int v = 1; v <= n; v++) {
				d[u][v] = c[u][v];
			}
		}
	
	//LOOP
	for(int k = 1; k <= n; k++) {
		for(int u = 1; u <= n; u++) {
			for(int v = 1; v <= n; v++) {
				if(d[u][v] > d[u][k] + d[k][v]) {
					d[u][v] = d[u][k] + d[k][v];
				}
			}
		}
	}
}

int main() {
	input();
	FloydWarshall();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
