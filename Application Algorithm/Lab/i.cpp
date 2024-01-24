#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m, cnt;
int head[MAXN], nxt[MAXN], to[MAXN], f[MAXN][2];
bool vis[MAXN], flag[MAXN];

void addEdge(int u, int v) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

void dfs(int u, int fa) {
    f[u][0] = 0;
    f[u][1] = 1;
    vis[u] = true;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == fa)
            continue;
        dfs(v, u);
        f[u][0] += f[v][1];
        f[u][1] += min(f[v][0], f[v][1]);
    }
}

bool check() {
    memset(vis, false, sizeof(vis));
    memset(flag, false, sizeof(flag));
    for (int i = 1; i <= m; i++)
        if (vis[i] == false) {
            dfs(i, 0);
            if (f[i][0] == 0)
                flag[i] = true;
        }
    for (int i = 1; i <= m; i++)
        if (flag[i] == false) {
            int u = to[i], v = to[i ^ 1];
            swap(u, v);
            memset(vis, false, sizeof(vis));
            dfs(u, 0);
            if (f[u][1] != m / 2)
                return false;
            memset(vis, false, sizeof(vis));
            dfs(v, 0);
            if (f[v][1] != m / 2)
                return false;
        }
    return true;
}

void solve(int u, int k) {
    if (u > m) {
        if (k == m / 2 && check())
            cnt++;
        return;
    }
    solve(u + 1, k);
    flag[u] = true;
    solve(u + 1, k + 1);
    flag[u] = false;
}

int main() {
    cin >> n;
    m = 2 * (n - 1);
    for (int i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        addEdge(u, i);
        addEdge(i, u);
        addEdge(v, i + 1);
        addEdge(i + 1, v);
    }
    solve(1, 0);
    cout << cnt << endl;
    return 0;
}
