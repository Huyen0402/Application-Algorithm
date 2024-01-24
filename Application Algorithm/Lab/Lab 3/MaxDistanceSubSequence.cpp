#include<bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int T;
int N, C;
int x[M];
int d_max;
int l, r, mid, res;

bool check(int d) {
        int cnt = 1, last = x[1];
        for(int i = 2; i <= N; i++) {
            if(last + d <= x[i]) {
                last = x[i];
                cnt++;
            } 
        }

        if(cnt >= C) return true;
        return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> N >> C;

        for(int i = 1; i <= N; i++) {
            cin >> x[i];
        }

        sort(x + 1, x + N + 1);

        l = 1, r = (x[N] - x[1]) / (C - 1), res = 1;

        while(l <= r) {
            mid = (l + r)/2;
            if(check(mid)) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << res << "\n";

    }
    
    return 0;
}