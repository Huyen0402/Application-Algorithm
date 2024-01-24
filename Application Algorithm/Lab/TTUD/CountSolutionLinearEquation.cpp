#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int n, m, ans = 0;

void recursive(int current, int i) {
    if (i == n - 1) {
        if ((m - current) % arr[i] == 0) {
            ans++;
        }
        return;
    }

    current += arr[i];
    while (current < m) {
        recursive(current, i + 1);
        current += arr[i];
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    recursive(0, 0);

    cout << ans;
}