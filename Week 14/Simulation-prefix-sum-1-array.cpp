#include<bits/stdc++.h>

using namespace std;

#define N 100001

int a[N];
int S[N];
int n;
int Q;
int i, j;
int res;

int main() {
	cin >> n;
	for(int k = 1; k <= n; k++) {
		cin >> a[k];
	}
	cin >> Q;
	
	S[0] = 0;
	for(int k = 1; k <= n; k++) {
		S[k] = S[k - 1] + a[k];
	}
	
	for(int q = 1; q <= Q; q++) {
		cin >> i >> j;
		res = S[j] - S[i - 1];
		cout << res << endl;
	}
	
	return 0;
}
