#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> d, complete_time;
vector<vector<int>> require;

void check_require(int task) {
    if (complete_time[task] != -1) {
        return;
    }

    int max_time = 0;
    
    for (int r : require[task]) {
        check_require(r);
        max_time = max(max_time, complete_time[r]);
    }

    complete_time[task] = d[task] + max_time;
} 

int main() {
    cin >> n >> m;

    d.resize(n + 1);
    complete_time.resize(n + 1, -1);
    require.resize(n + 1);

    for (int i = 1; i <=n; i++) {
        cin >> d[i];
    }

    for (int t = 0; t < m; t++) {
        int i, j;
        cin >> i >> j;
        require[j].push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        check_require(i);
        ans = max(ans, complete_time[i]);
    }

    cout << ans;
}