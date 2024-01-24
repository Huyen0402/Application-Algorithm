#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> height(m, vector<int>(n));
    vector<vector<int>> left(m, vector<int>(n));
    vector<vector<int>> right(m, vector<int>(n));

    for (int j = 0; j < n; j++) {
        height[0][j] = grid[0][j];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                height[i][j] = height[i - 1][j] + 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        stack<pair<int, int>> l_stack; // first is height, second is index
        for (int j = 0; j < n; j++) {
            while (!l_stack.empty() && l_stack.top().first >= height[i][j]) {
                l_stack.pop();
            }

            if (l_stack.empty()) {
                left[i][j] = -1;
            } else {
                left[i][j] = l_stack.top().second;
            }
            l_stack.push({ height[i][j], j });
        }

        stack<pair<int, int>> r_stack;
        for (int j = n - 1; j >= 0; j--) {
            while (!r_stack.empty() && r_stack.top().first >= height[i][j]) {
                r_stack.pop();
            }

            if (r_stack.empty()) {
                right[i][j] = n;
            } else {
                right[i][j] = r_stack.top().second;
            }
            r_stack.push({ height[i][j], j });
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, (right[i][j] - left[i][j] - 1) * height[i][j]);
        }
    }

    cout << ans;
}