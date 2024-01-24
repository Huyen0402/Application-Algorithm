#include <bits/stdc++.h>

using namespace std;

int t, n, k, low, high, mid;
int arr[100000];

bool is_possible(int x) {
    int last_number = arr[0];
    int count = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] - last_number >= x) {
            count++;
            last_number = arr[i];
        }
    }

    return count >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    cin >> t;

    while (t--) {
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        low = 1, high = 1200, mid;
        while (low < high) {
            mid = (low + high + 1) / 2;
            if (is_possible(mid)) {
                // cout << mid << '\n';
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        cout << low << '\n';
    }
}