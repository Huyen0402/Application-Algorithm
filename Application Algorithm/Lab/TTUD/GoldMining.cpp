#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l1, l2;
    cin >> n >> l1 >> l2;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d = l2 - l1 + 1;
    int k = floor(log2(d));
    int dp[n]; // max subsequence that meets conditions and ends at i
    int dp_pre[n]; // max subsequence that meets conditions and ends at or before i
    int pre[k + 1][n]; // min element in 2^j elements ending at i

    dp[0] = arr[0];
    dp_pre[0] = arr[0];
    for (int i = 0; i <= k; i++) {
        pre[i][0] = arr[0];
    }

    for (int i = 1; i < n; i++) {
        dp[i] = arr[i];
        if (i - l1 >= 0) {
            dp[i] += dp_pre[i - l1];

            int max_pre = 0;
            for (int j = max(i - l2, 0); j <= i - l1; j++) {
                max_pre = max(max_pre, dp[j]);
            }
            if (max_pre != dp_pre[i - l1]) {
                cout << "err " << i - l1 << "-" << dp_pre[i - l1] << '\n';
            }
        }

        pre[0][i] = dp[i];
        for (int j = 1; j <= k; j++) {
            if (i - (1 << (j - 1)) >= 0) {
                pre[j][i] = max(pre[j - 1][i], pre[j - 1][i - (1 << (j - 1))]);
            } else {
                pre[j][i] = pre[j - 1][i];
            }
        }

        if (i - d + (1 << k) - 1 >= 0) {
            dp_pre[i] = max(pre[k][i], pre[k][i - d + (1 << k) - 1]);
        } else {
            dp_pre[i] = pre[k][i];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}