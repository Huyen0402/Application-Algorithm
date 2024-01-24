#include <bits/stdc++.h> 

using namespace std;

#define N 10001

int a[N];
int n;
int S[N];

int computeS(int i) {
	if(i == 1) S[1] = 1;
	else {
		if(S[i] == 0) {
			S[i] = 1;
			for(int j = 1; j <= i - 1; j++) {
				if(a[j] < a[i]) {
					int tmp = computeS(j);
					if(S[i] < tmp + 1) S[i] = tmp + 1;
				}
			}
		}
	}
	return S[i];
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) S[i] = 0;
	int res = S[1];
	for(int i = 2; i <= n; i++) {
		int tmp = computeS(i);
		res = max(res, tmp);
	}
	
	cout << res;
	
	return 0;
}
