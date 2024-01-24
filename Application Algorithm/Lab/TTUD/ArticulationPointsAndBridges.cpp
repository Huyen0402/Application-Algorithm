#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> disc, low, parent;
vector<bool> ap, done;
int timer = 0;
int bridges = 0;

void dfs(int u) {
    if (done[u]) {
        return;
    }
    done[u] = true;
    timer++;

    disc[u] = timer;
    low[u] = timer;

    for (int child : adj[u]) {
        if (!done[child]) {
            parent[child] = u;
            dfs(child);
            low[u] = min(low[u], low[child]);
            if (parent[u] == -1) {
                int root_ap_children = 0;
                for (int child : adj[u]) {
                    if (parent[child] == u) {
                        root_ap_children++;
                    }
                }
                if (root_ap_children > 1) {
                    ap[u] = true;
                }
                // if (adj[u].size() > 1) {
                //     ap[u] = true;
                // }
            } else if (low[child] >= disc[u]) {
                ap[u] = true;
            }
            if (low[child] > disc[u]) {
                bridges++;
            }
        } else if (child != parent[u]) {
            low[u] = min(low[u], disc[child]);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int n, m, i, j;
    cin >> n >> m;

    adj.resize(n + 1);
    disc.resize(n + 1, INT32_MAX);
    low.resize(n + 1, INT32_MAX);
    parent.resize(n + 1, -1);
    ap.resize(n + 1, false);
    done.resize(n + 1, false);

    for (int t = 0; t < m; t++) {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    int ap_count = 0;
    for (int i = 1; i <= n; i++) {
        if (ap[i])
            ap_count++;
    }

    cout << ap_count << ' ' << bridges;
}