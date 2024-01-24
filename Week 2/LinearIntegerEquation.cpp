#include <bits/stdc++.h>

using namespace std;
#define N 1000
int x[N];
int n, M, T;

bool check(int v, int k) {
	if(k < n) return true;
	else return T + v == M;
}

void solution() {
	for(int i = 1; i <= n; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
}

void Try(int k) {
	for(int v = 1; v <= M - T - n + k; v++) {
		if(check(v, k)) {
			x[k] = v;
			T = T + x[k];
			if(k == n) solution();
			else Try(k + 1);
			T = T - x[k];
		}
	}
}

int main() {
	cin >> n >> M;
	T = 0;
	Try(1);
	
	return 0;
}
