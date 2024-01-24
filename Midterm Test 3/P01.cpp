#include<bits/stdc++.h>

using namespace std;

#define N 100001

int n;
int a[N];

int solve(int a[], int n) {
    map<int, int> f;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += f[a[i] - 1];
        ans += f[a[i] + 1];
        f[a[i]]++;
    }

    return ans;
}

int main() {
    cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

    int Q = solve(a, n);
    cout << Q << endl;

    return 0;
}
