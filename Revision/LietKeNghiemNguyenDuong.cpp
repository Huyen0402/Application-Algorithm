#include<bits/stdc++.h>

using namespace std;

#define MAX 500

int x[MAX];
int N, M;
int T;

int check(int v, int k) {
	if(k < N) return 1;
	return T + v == M;
}

void solution() {
	for(int i = 1; i <= N; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void Try(int k) {
	for(int v = 1; v <= M - T - (N - k); v++) {
		if(check(v, k)) {
			x[k] = v;
			T += x[k];
			if(k == N) solution();
			else Try(k + 1);
			T = T - x[k];
		}
	}
}

int main() {
	cin >> N >> M;
	Try(1);
	
	return 0;
}
