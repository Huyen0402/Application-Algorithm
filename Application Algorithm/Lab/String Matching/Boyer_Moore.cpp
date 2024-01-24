#include <bits/stdc++.h>

using namespace std;

string P, T;
int last[256];
int ans;

void conputeLast(string p) {
    for(int c = 0; c < 256; c++) last[c] = 0;
    int k = p.length();
    for(int i = k-1; i >= 0; i--) {
        if(last[p[i]] == 0) last[p[i]] = i;
    }
}

int boyerMoore(string P, string T) {
    conputeLast(P);
    int s = 0;
    int cnt = 0;
    int N = T.length();
    int M = P.length();
    while(s <= N-M) {
        int j = M-1;
        while(j >= 0 && T[j+s] == P[j])
            j = j - 1;
        if(j == -1) {
            cnt++; s = s + 1;
        } else {
            int k = last[T[j+s]];
            s = s + (j - k > 1 ? j - k : 1);
        }
    }
    return cnt;
}

int main() {
    getline(cin, P);
    getline(cin, T);
    int ans = boyerMoore(P, T);
    cout << ans << endl;
}