#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int>& a, int M) {
    int n = a.size();
    vector<vector<int> > dp(n + 1, vector<int>(M + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] += dp[i - 1][j];

            if (j >= a[i - 1]) {
                dp[i][j] += dp[i][j - a[i - 1]];
            }
        }
    }

    return dp[n][M];
}

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int solutions = solve(a, M);
    cout << solutions << endl;

    return 0;
}

