#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 20;
const int MAX_K = 10;

int N; // number of clients
int K; // number of trucks
int Q; // capacity of a truck
int d[MAX_N]; // d[v] is the demand of client v
int c[MAX_N][MAX_N];
int f, f_best;

int y[MAX_K]; // y[k] is the first client on route k
int x[MAX_N]; // x[k] is the next client of client k
bool visited[MAX_N];
int load[MAX_N]; // load[k] is the total demand of clients on route k
int segments;

void updateBest() {
	if(f < f_best) {
		f_best = f;
	}
	for(int k = 1; k <= K; k++) {
		cout << "Route[" << k << "]: 0";
		int v = y[k];
		while(v > 0) {
			cout << " - " << v;
			v = x[v];
		}
		cout << " - 0" << endl;
	}
	cout << f << endl;
	cout << "---------------------" << endl;
}

bool checkX(int v, int u, int k) {
	if(v == 0) return true;
	if(visited[v]) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void TryX(int u, int k) { // try all values for x[u] on route k
	for(int v = 0; v <= N; v++) {
		if(checkX(v, u, k)) {
			x[u] = v;
			visited[v] = true;
			f = f + c[u][x[u]];
			load[k] += d[v];
			segments += 1;
			if(v == 0) {
				if(k == K) {
					if(segments == N + K) updateBest();
				} else {
					TryX(y[k + 1], k + 1);
				}
			} else {  // v is client
				TryX(v, k);
			}
			visited[v] = false;
			f = f - c[u][x[u]];
			load[k] -= d[v];
			segments -= 1;
		}
	}
}

bool checkY(int v, int k) {
	if(visited[v]) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void TryY(int k) { // try all values for y[k] (y[1] < y[2] < ... < y[K])
	for(int v = y[k - 1] + 1; v <= N; v++) {
		if(checkY(v, k)) {
			y[k] = v;
			load[k] += d[v];
			visited[v] = true;
			f = f + c[0][y[k]];
			segments += 1;
			if(k == K) {
				TryX(y[1], 1);
			} else {
				TryY(k + 1);
			}
			load[k] -= d[v];
			visited[v] = false;
			f = f - c[0][y[k]];
			segments -= 1;
		}
	}
}

void input() {
	cin >> N >> K >> Q;
	for(int i = 1; i <= N; i++) cin >> d[i];
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= N; j++) {
			cin >> c[i][j];
		}
	}
}

void solve() {
	for(int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	for(int k = 1; k <= K; k++) {
		load[k] = 0;
	}
	segments = 0;
	f = 0;
	f_best = 1e9;
	y[0] = 0;
	TryY(1);
}

int main() {
	input();
	solve();
	cout << f_best;
	return 0;
}
