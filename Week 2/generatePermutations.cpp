#include <bits/stdc++.h>

using namespace std;
#define N 1000
int x[N];
int n;

bool check(int v, int k) {
	for(int i = 1; i < k; i++) {
		if(x[i] == v) return false;
	}
	return true;
}

void solution() {
	for(int i = 1; i <= n; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
}

void Try(int k) {
	for(int v = 1; v <= n; v++) {
		if(check(v, k)) {
			x[k] = v;
			if(k == n) solution();
			else Try(k + 1);
		}
	}
}

int main() { 
	cin >> n;
	Try(1);
	
	return 0;
}
