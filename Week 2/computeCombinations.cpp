#include <bits/stdc++.h>

using namespace std;

#define N 1000
const int P = 1e9 + 7;
int M[N][N];

int C(int k, int n) {
	if(k == 0 || k == n) {
		M[k][n] = 1;
	} else {
		if(M[k][n] == 0) {
			M[k][n] = (C(k, n - 1) % P + C(k - 1, n - 1) % P) % P;
		}
	}
	
    return M[k][n];
}

int main() {
    int k, n;
    cin >> k >> n;

    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
    		M[i][j] = 0;
		}
	}
	
	int result = C(k, n);

    cout << result << endl;

    return 0;
}
