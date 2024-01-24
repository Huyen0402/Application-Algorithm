#include<bits/stdc++.h>

using namespace std;

#define N 10001
#define pii pair<int, int>
const int INF = 1e9;

int n, m;
int C[N], D[N];
int level[N];
int f[N][N];
int d[N];
vector<int> A[N];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> C[i] >> D[i];
	}
	
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
}

void bfs(int s) {
	queue <int> Q;
	for (int i = 0; i <= n; i++) {
		level[i] = -1;
	}
	Q.push(s); level[s] = 0;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < A[u].size(); i++) {
			int v = A[u][i];
			if (level[v] == -1 && level[u] < D[s]) {
				Q.push(v);
				level[v] = level[u] + 1;
				f[s][v] = C[s];
			}
		}
	}
}

void computeCostGraph() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = INF;
		}
	}
	
	for (int s = 1; s <= n; s++) {
		bfs(s);
	}
}

int selectMin(set<int>& F) {
	int minD = INF; int select = -1;
	for(set<int>::iterator p = F.begin(); p != F.end(); p++) {
		int v = *p;
		if(d[v] < minD) {
			minD = d[v];
			select = v;
		}
	}
	return select;
}

void dijkstra() {
	set<int> F;
	for(int v = 1; v <= n; v++) {
		d[v] = INF;
	}
	d[1] = 0;
	for(int i = 1; i <= n; i++) {
		F.insert(i);
	}
	while(F.size() > 0) {
		int u = selectMin(F);
		F.erase(u);
		if(u == n) break;
		for(set<int>::iterator p = F.begin(); p != F.end(); p++) {
			int v = *p;
			if (d[v] > d[u] + f[u][v]) {
				d[v] = d[u] + f[u][v];
			}
		}
	}
	
	cout << d[n];	
}

void dijkstraPriorityQueue() {
    for (int v = 1; v <= n; v++) {
        d[v] = INF;
    }
    priority_queue<pii, vector<pii>, greater<pii> > F;
    F.push(make_pair(0, 1));
    d[1] = 0;
    while (!F.empty()) {
        pii p = F.top(); F.pop();
        int u = p.second;
        if (u == n) break;
        for (int v = 1; v <= n; v++) {
			if (d[v] > d[u] + f[u][v]) {
				d[v] = d[u] + f[u][v];
				F.push(make_pair(d[v], v));
			}
        }
    }
    cout << d[n];
}

int main() {
	input();
	computeCostGraph();
	//dijkstra();
	dijkstraPriorityQueue();
	
	return 0;
}
