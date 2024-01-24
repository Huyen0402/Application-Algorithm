#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
int n, k, A, B;
int a[N], S[N];
int Q = 0;

void input() {
    cin >> n >> k >> A >> B;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    
    for(int i = 1; i <= n; i++) {
        S[i] = 0;
    }
    for(int i = 1; i <= k; i++) {
        S[1] += a[i];
    }

    for(int i = 2; i <= n - k + 1; i++) {
        S[i] = S[i - 1] - a[i - 1] + a[i + k - 1];        
    }

    for (int i = 1; i <= n - k + 1; i++) {
        if(S[i] >= A && S[i] <= B) {
            Q += 1;
        }
    }
    cout << Q;
    return 0;
}