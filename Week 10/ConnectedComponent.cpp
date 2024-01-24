#include <bits/stdc++.h>
using namespace std;

#define N 100001

int n, m; // number of nodes and edges
vector<int> Adj[N]; // Adj[u] is the list of adjacent nodes of v
int cc[N]; //cc[v] is the index of the connected component containing v
int nbCC; //number of connected components

void dfs(int u) {
    cc[u] = nbCC; // u is contained in the current connected component
    for (int i = 0; i < Adj[u].size(); i++) {
    	int v = Adj[u][i];
    	if (cc[v] < 0) {
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
    
    for (int v = 1; v <= n; v++) cc[v] = -1;

    for (int v = 1; v <= n; v++) {
    	if (cc[v] < 0) {
    		nbCC++;
    		dfs(v);
		}
	}
	
	/*
	for (int c = 1; c <= nbCC; c++) {
		cout << "Connected Component " << c << ": ";
		for (int v = 1; v <= n; v++) {
			if (cc[v] == c) cout << v << " ";
		}
		cout << endl;
	}
	*/
	
	cout << nbCC;

    return 0;
}
