#include <bits/stdc++.h>

using namespace std;

bool valid_state(long long bitmask, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (bitmask & (1 << i)) {
            if (!(bitmask & 1 << (i + n))) {
                k--;
            }
        } else {
            if (bitmask & 1 << (i + n)) {
                return false;
            }
        }
    }

    return k >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    short int c[2 * n + 1][2 * n + 1];

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
        }
    }

    int max_bitmask = (1 << (2 * n)) - 1;

    int** dp = new int*[max_bitmask + 1];
    for (int i = 0; i <= max_bitmask; i++) {
        dp[i] = new int[2 * n + 1];
        for (int j = 0; j <= 2 * n; j++) {
            dp[i][j] = -1;
        }
    }

    // memset(dp, -1, sizeof(dp));
    dp[0][0] = 0; // pass station 0, end at station 0

    for (int bitmask = 1; bitmask <= max_bitmask; bitmask++) {
        if (!valid_state(bitmask, n, k)) {
            continue;
        }
        for (int j = 1; j <= 2 * n; j++) { // end at station j
            long long pre_bitmask = bitmask & ~(1 << (j - 1)); // previous state
            if (pre_bitmask >= bitmask) { // check if bit j is in state
                continue;
            }

            for (int t = 0; t <= 2 * n; t++) { // previous state, end at station t
                if (dp[pre_bitmask][t] != -1) {
                    if (dp[bitmask][j] == -1) {
                        dp[bitmask][j] = dp[pre_bitmask][t] + c[t][j];
                    } else {
                        dp[bitmask][j] = min(dp[bitmask][j], dp[pre_bitmask][t] + c[t][j]);
                    }
                }
            }
        }
    }

    int ans = INT32_MAX;
    for (int i = n + 1; i <= 2 * n; i++) {
        ans = min(ans, dp[max_bitmask][i] + c[i][0]);
    }

    cout << ans;

    // for (int i = 0; i <= max_bitmask; i++) {
    //     delete[] dp[i];
    // }
    // delete[] dp;
}