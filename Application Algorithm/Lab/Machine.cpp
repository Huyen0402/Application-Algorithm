#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e6;
const int INF = (int) 1e9;
int n, L[N+1], R[N+1];

inline void Read(int &n) {
    char c; n = 0;
    do {
        c = getchar();
    } while (!isdigit(c));

    do {
        n = n * 10 + c - 48;
        c = getchar();
    } while (isdigit(c));
}

void solve() {
    for(int i = 0; i <= N+1; i++) L[i] = R[i] = -INF;
    Read(n);
    while(n--) {
        int a, b; Read(a); Read(b);
        L[b] = max(L[b], b-a);
        R[a] = max(R[a], b-a);
    } 

    for(int i = 1; i <= N; ++i) L[i] = max(L[i-1], L[i]);
    for(int i = N; i >= 1; --i) R[i] = max(R[i+1], R[i]);
    int ans = -INF;
    for(int i = 1; i <= N-1; ++i) ans = max(ans, L[i] + R[i+1]);
    if(ans == -INF) ans = -1;
    cout << ans << endl;
}

int main() {
    solve();
}