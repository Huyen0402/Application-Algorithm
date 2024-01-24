#include <bits/stdc++.h>

using namespace std;

int n, M;
int a[102], t[102], x[102];
int f, result;


void solution() {
    if(f == M) {
        result ++;
    }
}

void Try(int k) {
    for(int v = 1; v <= (M - f - (t[n] - t[k])/a[k]); v++){
        x[k] = v;
        f += a[k]*x[k];
        if(k == n) {
            solution();
        }else {
            Try(k+1);
        }
        f -= a[k]*x[k];
    }
}

void input() {
    cin >> n >> M;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void solve() {
    f = 0;
    result = 0;
    Try(1);
    cout << result;
}

int main() {
    input();
    solve();
    return 0;
}