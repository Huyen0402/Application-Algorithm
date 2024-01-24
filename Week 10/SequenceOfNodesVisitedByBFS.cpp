#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> Adj[1001]; // Adj[u] is the list of adjacent nodes of u
int d[1001]; //d[v] is the shortest distance from u (start node) to v measured in term of number of edges in the path

void bfs(int u) {
    queue<int> Q;
    Q.push(u);
    d[u] = 0;
    cout << u << " ";

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (int i = 0; i < Adj[v].size(); i++) {
            int w = Adj[v][i];
            if (d[w] < 0) {
                Q.push(w);
                d[w] = d[v] + 1;
                cout << w << " ";
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
    
    for (int v = 1; v <= n; v++) {
        d[v] = -1;
    }

    for (int u = 1; u <= n; u++) {
        if (d[u] < 0) {
        	bfs(u);
		}
    }

    return 0;
}
