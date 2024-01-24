#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;
int n;
long long a[N], S[N], f[2], res = -1e18;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

}

void solve() {
    int tmp;

    for(int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + a[i];
    }

    f[1] = 1e18;

    for(int i = 1; i <= n; i++) {
        tmp = abs(S[i]) % 2;
        if(f[tmp] != 1e18) res = max(res, S[i] - f[tmp]);
        f[tmp] = min(f[tmp], S[i]);
    }

    if(res == -1e18) cout << "NOT_FOUND\n";
    else cout << res << "\n";
}

int main() {
    input();
    solve();
    return 0;
}