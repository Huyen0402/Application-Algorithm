#include <bits/stdc++.h>
using namespace std;

int n, m; // number of nodes and edges
vector<int> Adj[1001]; // Adj[u] is the list of adjacent nodes of v
vector<int> cc; // cc[v] is the index of the connected component containing v
int nbCC; // number of connected components

void dfs(int start) {
    stack<int> stk;
    stk.push(start);
    cc[start] = nbCC;

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();

        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i];
            if (cc[v] < 0) {
                stk.push(v);
                cc[v] = nbCC;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    for (int u = 1; u <= n; u++) {
        sort(Adj[u].begin(), Adj[u].end());
    }

    cc.assign(n + 1, -1); // Initialize cc vector

    for (int v = 1; v <= n; v++) {
        if (cc[v] < 0) {
            nbCC++;
            dfs(v);
        }
    }

    cout << nbCC;

    return 0;
}
