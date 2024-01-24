#include<bits/stdc++.h>

using namespace std;

#define N 1000001

struct Edge{
	int u, v, w;
};

Edge E[N];

int n, m;
int p[N], r[N];

void makeSet(int u) {
	p[u] = u; r[u] = 0;
}

int Find(int v){
	if(p[v] != v) p[v] = Find(p[v]);
	return p[v];	
}

void Unify(int x, int y) {
	if(r[x] > r[y]) {
		p[y] = x;
	} else {
		p[x] = y;
		if(r[y] == r[x]) r[y]++;
	}
}

bool cmp(Edge& e1, Edge& e2) {
	return e1.w < e2.w;
}

void Kruskal() {
	for(int v = 1; v <= n; v++) makeSet(v);
	sort(E, E + m, cmp);
	long long res = 0;
	int cnt = 0;
	for(int i = 0; i < m; i++) {
		int u = E[i].u; int v = E[i].v;
		int ru = Find(u); int rv = Find(v);
		if(ru != rv) {
			res = res + E[i].w;
			Unify(ru, rv);
			cnt++;
			if(cnt == n - 1) break;
		}
	}
	
	cout << res;
}

void input() {
	cin >> n >> m;
	for(int k = 1; k <= m; k++) {
		cin >> E[k - 1].u >> E[k - 1].v >> E[k - 1].w;
	}
}

int main() {
	input();
	Kruskal();
	return 0;
}
