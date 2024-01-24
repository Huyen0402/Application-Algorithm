#include <bits/stdc++.h>

using namespace std;

int n, m, scc = 0;
vector<vector<int>> adj, reversed_adj;
vector<int> visited;
stack<int> ldv; // last discovered vertice

void input() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    adj.resize(n + 1);
    reversed_adj.resize(n + 1);

    int i, j;
    for (int t = 0; t < m; t++) {
        cin >> i >> j;
        adj[i].push_back(j);
        reversed_adj[j].push_back(i);
    }
}

void dfs(int s) {
    if (visited[s]) {
        return;
    }
    visited[s] = true;

    for (int v : adj[s]) {
        dfs(v);
    }

    ldv.push(s);
}

void dfs_reverse(int s) {    
    if (visited[s]) {
        return;
    }
    visited[s] = true;

    for (int v : reversed_adj[s]) {
        dfs_reverse(v);
    }
}

void solve() {
    visited.resize(n + 1, false);
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    visited.clear();
    visited.resize(n + 1, false);
    while (!ldv.empty()) {
        int i = ldv.top();
        ldv.pop();
        if (visited[i]) {
            continue;
        }
        scc++;
        dfs_reverse(i);
    }
}

int main() {
    input();
    solve();
    cout << scc;
}