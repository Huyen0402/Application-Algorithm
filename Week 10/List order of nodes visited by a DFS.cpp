#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> Adj[1001]; // Adj[u] là danh sách các d?nh k? c?a u
vector<bool> bVisited(1001, false);

void dfs(int u) {
    bVisited[u] = true;
    cout << u << " ";
    for (int i = 0; i < Adj[u].size(); i++) {
    	int v = Adj[u][i];
    	if (!bVisited[v]) {
    		dfs(v);
		}
	}
}

int main() {
    int n, m;
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

    for (int v = 1; v <= n; v++) {
    	if (!bVisited[v]) {
    		dfs(v);
		}
	}

    return 0;
}
