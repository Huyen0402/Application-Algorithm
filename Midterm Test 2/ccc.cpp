#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// Function to compute F(n)
int computeF(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    int result = computeF(n);
    cout << result << endl;

    return 0;
}
