#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int N = 1e6 + 2;
int n, L1, L2;
long long a[N], f[N], res = -1e18;
priority_queue<ii> hd;


void input() {
    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

void solve() {
    for(int i = 1; i <= n; i++) {
        if(i - L1 > 0) hd.push(ii(f[i - L1], i - L1));
        while(!hd.empty()) {
            if(hd.top().second < i - L2) hd.pop();
            else break;
        }

        if(hd.empty()) f[i] = a[i];
        else f[i] = hd.top().first + a[i];
        res = max(f[i], res);
    }

    cout << res << "\n";
}


int main() {
    input();
    solve();

    return 0;
}