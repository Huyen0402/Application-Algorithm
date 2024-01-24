#include<bits/stdc++.h>

using namespace std;

int n;

int ans(int a[], int n) {
    int sum[n];
    if(n >= 1) sum[0] = a[0];
    if(n >= 2) sum[1] = a[0] + a[1];
    if(n > 2) sum[2] = max(sum[1], max(a[1] + a[2], a[0] + a[2]));

    for(int i = 3; i < n; i++) {
        sum[i] = max(max(sum[i - 1], sum[i - 2] + a[i]), a[i] + a[i - 1] + sum[i - 3]);
    }

    return sum[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << ans(a, n);

    return 0;

}