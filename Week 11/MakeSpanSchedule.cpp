#include<bits/stdc++.h>

using namespace std;
#define N 10001

vector<int> A[N]; //a[v] is the list of adjacent nodes of v
int n, m;
int d[N]; //d[v] is the duration of task v
vector<int> topo;
int a[N]; // the number of arc entering v
int S[N]; //S[v] is the time when task v can start

void input() {
	cin >> n >> m;
	for(int v = 1; v <= n; v++) cin >> d[v];
	for(int v = 1; v <= n; v++) a[v] = 0;
	for(int k = 1; k <= m; k++) {
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		a[v]++;
	}
}

void topoSort() {
	queue<int> Q;
	for(int v = 1; v <= n; v++) {
		if(a[v] == 0) Q.push(v);
	}
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		topo.push_back(u);
		for(int i = 0; i < A[u].size(); i++) {
			int v = A[u][i];
			a[v] = a[v] - 1;
			if(a[v] == 0) Q.push(v);
		}
	}
}

void solve() {
	for(int v = 1; v <= n; v++) S[v] = 0;
	int res = 0;
	for(int i = 0; i < topo.size(); i++) {
		int u = topo[i];
		//fix S[u]
		res = max(res, S[u] + d[u]);
		for(int j = 0; j < A[u].size(); j++) {
			int v = A[u][j];
			S[v] = max(S[v], S[u] + d[u]);
		}
	}
	cout << res;
}

int main() {
	input();
	topoSort();
	solve();
	
	return 0;
}
