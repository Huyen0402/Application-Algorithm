#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, d;
    cin >> n >> t >> d;

    int goods[n], load_time[n];
    for (int i = 0; i < n; i++) {
        cin >> goods[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> load_time[i];
    }

    int dp[n][t + 1]; // max goods can be load within first ith warehouses and max load_time j, last warehouse picked is i;
    memset(dp, 0, sizeof(dp));

    for (int j = 0; j <= t; j++) {
        if (j - load_time[0] >= 0) {
            dp[0][j] = goods[0];   
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= t; j++) {
            if (j - load_time[i] >= 0) {
                for (int k = 1; i - k >= 0 && k <= d; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - k][j - load_time[i]] + goods[i]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i][t]);
    }

    cout << ans;
}