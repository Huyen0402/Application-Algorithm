#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000000];
int mem[1000000][20];

void preCompute() {
    int m = floor(log2(n));
    // mem.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        mem[i][0] = arr[i];
    }

    for (int j = 1; 1 << j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (i + (1 << (j - 1)) >= n) {
                mem[i][j] = mem[i][j - 1];
            } else {
                mem[i][j] = min(mem[i][j - 1], mem[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}

int getMinimum(int i, int j) {
    int d = j - i + 1;
    int k = floor(log2(d));
    return min(mem[i][k], mem[j - (1 << k ) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    // arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    preCompute();

    int m, i, j;
    cin >> m;
    long long ans = 0;
    for (int t = 0; t < m; t++) {
        cin >> i >> j;
        if (i >= j) {
            cout << i << j;
        }
        ans += getMinimum(i, j);
    }

    cout << ans;
}