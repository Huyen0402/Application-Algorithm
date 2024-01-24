#include<bits/stdc++.h>

using namespace std;

#define N 100001
#define pii pair<int, int>
const int INF = 1e9;

struct Arc{
	int node; // 
	int w; // 
	Arc(int _node, int _w) {
		node = _node;
		w = _w;
	}
};

vector<Arc> A[N]; //A[v] is 
int n, m;
int s, t;
int d[N]; //d[v] is the upper bound of the length of the shortest path
int p[N]; //p[v] is the predecessor of v on the upper-bound path

void input() {
	cin >> n >> m;
	for(int k = 1; k <= m; k++) {
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back(Arc(v, w));
	}
	cin >> s >> t;
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

int dijkstra() {
	set<int> F;
	for(int v = 1; v <= n; v++) {
		d[v] = INF; p[v] = -1;
	}
	d[s] = 0;
	for(int i = 1; i <= n; i++) {
		F.insert(i);
	}
	while(F.size() > 0) {
		int u = selectMin(F);
		F.erase(u);
		if(u == t) return d[t];
		for(int i = 0; i < A[u].size(); i++) {
			int v = A[u][i].node;
			int w = A[u][i].w;
			if(F.find(v) != F.end()) {
				if(d[v] > d[u] + w) {
					d[v] = d[u] + w;
					p[v] = u;
				}
			}
		}
	}
}

int dijkstraPriorityQueue() {
	for(int v = 1; v <= n; v++) {
		d[v] = INF;
	}
	priority_queue<pii, vector<pii>, greater<pii> > F;
	F.push(make_pair(0, s));
	d[s] = 0;
	while(!F.empty()) {
		pii p = F.top(); F.pop();
		int u = p.second;
		if(u == t) return d[t];
		for(int i = 0; i < A[u].size(); i++) {
			int v = A[u][i].node;
			int w = A[u][i].w;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				F.push(make_pair(d[v], v));
			}
		}
	}
	return -1;
}

int main() {
	input();
	//int res = dijkstra();
	int res = dijkstraPriorityQueue();
	cout << res;
	
	return 0;
}
