#include <iostream>

using namespace std;

#define H 100

int N, M;
int c[H];
int A[H][H];
int load[H];
bool done[H];
int x[H];
int res;

void input() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		cin >> c[i];
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
}

bool check(int v, int k) {
	if(done[k]) return false;
	for(int i = 1; i <= N; i++) {
		if(A[v][i] == 1 && !done[i]) {
			return false;
		}
	}
	
	return true;
}

void solution() {
	int maxLoad = 0;
	for(int i = 1; i <= M; i++) {
		maxLoad = max(maxLoad, load[i]);
	}
	if(maxLoad < res) res = maxLoad;
}

void Try(int k) {
	for(int v = 1; v <= M; v++) {
		if(check(v, k)) {
			x[k] = v;
			load[v] += c[k];
			done[k] = true;
			if(k == N) solution();
			else Try(k + 1);
			load[v] -= c[k];
			done[k] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	input();
	
	for(int i = 1; i <= N; i++) done[i] = false;
	for(int i = 1; i <= M; i++) load[i] = 0;
	
	res = INT_MAX;
    Try(1);
    std::cout << res;
	
	return 0;
}
