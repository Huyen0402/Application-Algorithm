#include <bits/stdc++.h>
using namespace std;

int pi[100001];

void computePi(string p) {
    pi[1] = 0;
    int k = 0;
    for(int q = 2; q < p.length(); q++) {
        while(k > 0 && p[k+1] != p[q]) k = pi[k];
        if(pi[k+1] == p[q]) k = k+1;
        pi[q] = k;
    }
}

int kmp(string P, string T) {
    P = '-' + P;
    T = '-' + T;
    computePi(P);
    int cnt = 0;
    int N = T.length() - 1;
    int M = P.length() - 1;
    int q = 0;
    for(int i = 1; i <= N; i++) {
        while(q > 0 && P[q+1] != T[i]) q = pi[q];
        if(P[q+1] == T[i]) q = q + 1;
        if(q == M) {
            cnt += 1;
            q = pi[q];
        }
    }
    return cnt;
}

int main() {
    string P, T;
    getline(cin, P);
    getline(cin, T);
    int ans = kmp(P, T);
    cout << ans << endl;
}