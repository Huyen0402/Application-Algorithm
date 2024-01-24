#include <iostream>
#include <vector>

using namespace std;
// Function to compute C(k, n) using dynamic programming
int computeCombinations(int k, int n) {
    vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;
        }
    }

    return dp[n][k];
}

int main() {
    int k, n;
    cin >> k >> n;

    int result = computeCombinations(k, n);

    cout << result << endl;

    return 0;
}

