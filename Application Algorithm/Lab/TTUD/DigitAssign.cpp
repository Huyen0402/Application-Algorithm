#include <bits/stdc++.h>

using namespace std;

int v_map[] = {100, 10, 2, -100, 1000, 100, 10 };
int n, sum = -62, ans = 0;
bool assigned[10];
// string trace = "ICT-K62+HUST";
// int i_map[] = {0, 1, 2, 4, 8, 9, 10};

void try_assign(int index) {
    if (index >= 7) {
        if (sum == n) {
            // cout << trace << " = " << sum << '\n';
            ans++;
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (assigned[i]) {
            continue;
        }
        sum += i * v_map[index];
        assigned[i] = true;
        // trace[i_map[index]] = '0' + i;
        // if (index == 2) {
        //     trace[11] = '0' + i;
        // }
        try_assign(index + 1);
        assigned[i] = false;
        sum -= i * v_map[index];
    }
}

int main() {
    cin >> n;

    memset(assigned, false, sizeof(assigned));
    try_assign(0);

    cout << ans;
}