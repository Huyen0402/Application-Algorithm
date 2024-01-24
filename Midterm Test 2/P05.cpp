#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

long long computeF(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i <= n; i++) {
        dp[i] = (2 * dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    long long result = computeF(n);
    cout << result << endl;

    return 0;
}
