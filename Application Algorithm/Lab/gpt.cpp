#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 5005;
vector<int> adj[MAXN];
int dp[2][MAXN];
int cnt[2][MAXN];
int n;

void dfs(int u, int p) {
    dp[0][u] = 0;
    dp[1][u] = 1;
    cnt[0][u] = 1;
    cnt[1][u] = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u);
            cnt[0][u] += cnt[1][v];
            cnt[1][u] += cnt[0][v];
            dp[0][u] += dp[1][v] + cnt[1][v];
            dp[1][u] += dp[0][v] + cnt[0][v];
        }
    }
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1][1] << endl;
    return 0;
}