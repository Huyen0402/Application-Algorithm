#include <bits/stdc++.h>

using namespace std;

int m, n, r, c;
vector<vector<int>> directions = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

bool validatePoint(vector<vector<int>>& maze, int r, int c) {
    int m = maze.size(), n = maze[0].size();

    if (r < 0 || r >= m || c < 0 || c >= n) {
        return false;
    }
    if (maze[r][c]) {
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> r >> c;
    r--;
    c--;

    vector<vector<int>> maze(m, vector<int>(n, 0));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    queue<vector<int>> q;
    q.push({ r, c, 1 });
    int ans = -1;
    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        for (auto d : directions) {
            int row = current[0] + d[0], col = current[1] + d[1];
            int step = current[2] + 1;

            if (validatePoint(maze, row, col)) {
                if (row == 0 || col == 0 || row == m - 1 || col == n - 1) {
                    ans = step;
                    break;
                }
                if (!visited[row][col]) {
                    q.push({ row, col, step });
                    visited[row][col] = true;
                }
            }
        }

        if (ans != -1) {
            break;
        }
    }

    cout << ans;
}