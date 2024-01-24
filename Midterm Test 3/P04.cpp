#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int inf = INT_MAX;

int solve(int n, int K, int Q, vector<int>& d, vector<vector<int> >& dist_matrix, vector<pair<int, int> >& F) {
    vector<vector<vector<int> > > dp(K + 1, vector<vector<int> >(n + 1, vector<int>(n + 1, inf)));

    for (int i = 0; i <= n; ++i) {
        dp[0][i][i] = 0;
    }

    for (int i = 1; i <= K; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1]);
                for (int l = 0; l < Q; ++l) {
                    if (F[l].first <= k && k <= F[l].second) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][F[l].first - 1] + dist_matrix[F[l].first - 1][k]);
                    }
                }
            }
        }
    }

    int ans = inf;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[K][n][i] + dist_matrix[i][0]);
    }

    if (ans == inf) {
        return -1;
    } else {
        return ans;
    }
}

int main() {
    int n, K, Q;
    cin >> n >> K >> Q;

    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    vector<vector<int> > dist_matrix(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> dist_matrix[i][j];
        }
    }

    int M;
    cin >> M;

    vector<pair<int, int> > F(M);
    for (int i = 0; i < M; ++i) {
        cin >> F[i].first >> F[i].second;
    }

    int result = solve(n, K, Q, d, dist_matrix, F);
    cout << result << endl;

    return 0;
}
