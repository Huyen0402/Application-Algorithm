#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int n, m;
vector<int> A[N];
bool visited[N];
int num[N], low[N];
int t;
vector<pair<int, int> > bridges;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void dfs(int u, int p) { // DFS from v with p is the parent node of node u in the DFS tree
    t++;
    num[u] = t;
    low[u] = num[u];
    visited[u] = true;
    for(int i = 0; i < A[u].size(); i++) {
        int v = A[u][i];
        if(v == p) continue;
        if(visited[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > num[u]) {
                // discover a bridges (u, v)
                bridges.push_back(make_pair(v, u));
            }
        }
    }
}

void init() {
    for(int v = 1; v <= n; v++) visited[v] = false;
}

void solve() {
    init();
    t = 0;
    for(int s = 1; s <= n; s++) {
        if(!visited[s]) {
            dfs(s, -1);
        }
    }
    cout << "bridges = ";
    for(int i = 0; i < bridges.size(); i++) {
        cout << "(" << bridges[i].first << "," << bridges[i].second << ") ";
    }
}

int main() {
    input();
    solve();
}