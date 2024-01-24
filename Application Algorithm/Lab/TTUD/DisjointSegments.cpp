#include <bits/stdc++.h>

using namespace std;

struct custom_comparator {
    inline bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), custom_comparator());

    int last_end = arr[0].second;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i].first > last_end) {
            ans++;
            last_end = arr[i].second;
        }
    }

    cout << ans;
}