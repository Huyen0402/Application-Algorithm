#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int maxN = 999 + 100;
const int oo = 1e9 + 7;
int a[maxN][maxN], m, n, r, c, d[maxN][maxN];
// a[maxN][maxN] đánh dấu một ô đã xét hay chưa
// d[maxN][maxN] lưu độ dài đường đi từ ô xuất phát
int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};

queue<ii> qe; // lưu các ô lân cận sẽ được xét

void input() {
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
}

int solve() {
    qe.push(ii(r, c)); // đẩy ô xuất phát vào cuối queue 
    d[r][c] = 0; // quãng đường ban đầu bằng 0
    a[r][c] = 1; // đánh dấu đã xét ô xuất phát
    while(!qe.empty()) {
        ii u = qe.front(); qe.pop(); // lấy u bằng phần tử đầu queue và xóa phần tử đầu queue
        for(int i = 0; i < 4; i++) { // loang
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if(x < 1 || x > m || y < 1 || y > n)  // nếu gặp biên thì trả về độ dài quãng đường
                return d[u.first][u.second] + 1;
            if(a[x][y] != 1) { // nếu a[x][y] chưa xét thì +1 
                d[x][y] = d[u.first][u.second] + 1;
                qe.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> r >> c;
    input();
    int ans = solve();
    cout << ans;
    return 0;
}