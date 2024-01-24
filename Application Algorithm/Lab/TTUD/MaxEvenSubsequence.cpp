#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long even_dp[n]; // max even subsequence ending at i
    long long odd_dp[n]; // max odd subsequence ending at i

    // first dp elements of odd_dp and even_dp
    if (arr[0] % 2 == 0) {
        even_dp[0] = arr[0];
        odd_dp[0] = 0; // 0 means no odd_dp ends at i
    } else {
        even_dp[0] = -1; // -1 means no even_dp ends at i
        odd_dp[0] = arr[0];
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] % 2 == 0) { // if arr[i] is even
            if (even_dp[i - 1] < 0) { // whether previous even_dp doesn't exist or it is negative
                even_dp[i] = arr[i];
            } else { // add to previous even_dp
                even_dp[i] = arr[i] + even_dp[i - 1];
            }

            if (odd_dp[i - 1]) { // add to previous odd_dp if exists
                odd_dp[i] = arr[i] + odd_dp[i - 1];
            } else { // or no odd_dp ends at i
                odd_dp[i] = 0;
            }
        } else {
            if (even_dp[i - 1] < 0) { // whether previous even_dp doesn't exist or it is negative
                odd_dp[i] = arr[i];
            } else { // add to previous even_dp
                odd_dp[i] = arr[i] + even_dp[i - 1];
            }

            if (odd_dp[i - 1]) { // add to previous odd_dp if exists
                even_dp[i] = arr[i] + odd_dp[i - 1];
            } else { // or no even_dp ends at i
                even_dp[i] = -1;
            }
        }
    }

    long long ans = INT32_MIN + 1;
    for (int i = 0; i < n; i++) {
        if (even_dp[i] != -1) {
            ans = max(ans, even_dp[i]);
        }
    }

    if (ans != INT32_MIN + 1) {
        cout << ans;
    } else {
        cout << "NOT_FOUND";
    }
}