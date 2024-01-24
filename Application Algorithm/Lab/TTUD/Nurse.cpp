#include <bits/stdc++.h>

using namespace std;

const int m = 1e9 + 7;

int main() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    long long dp[n + 1]; // number of possible plans where i + 1 is a day-off
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = i - k1; j >= i - k2; j--) { // j is a day-off
            if (j >= 1) {
                tmp += dp[j - 1];
            } else if (j == 0) {
                tmp ++;
            }
        }

        dp[i] = tmp;
    }

    cout << dp[n] + dp[n - 1]; 
}