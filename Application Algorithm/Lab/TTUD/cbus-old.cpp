#include <bits/stdc++.h>
 
using namespace std;
 
bool passengersCount(unsigned int bitmask, int k, int n) {
    for (int i = 0; i < n; i++) {
        if (bitmask & 1) k--;
        bitmask /= 2;
    }
    for (int i = 0; i < n; i++) {
        if (bitmask & 1) k++;
        bitmask /= 2;
    }
    return k <= 0;
}
 
int main() {
    unsigned int n, k, i, j, tmp, bm;
    cin >> n >> k;
    int lc = n << 1;
    unsigned int m[lc + 1][lc + 1];
    for (i = 0; i <= lc; i++) {
        for (j = 0; j <= lc; j++) {
           cin >> m[i][j];
        }        
    }
 
    unsigned int allMask = 1 << lc, preMask;
    unsigned int distance[allMask][lc + 1];
    memset(distance, 0, sizeof(distance));
 
    for (i = 1; i <= n; i++) distance[1 << i >> 1][i] = m[0][i];
 
    for (bm = 1; bm < allMask; bm++) {
        for (i = 1; i <= lc; i++) { // to station i
            if (!(bm & 1 << i >> 1)) continue;
            preMask = bm ^ (1 << i >> 1);
            if (i <= n && ((bm & 1 << i + n >> 1) || passengersCount(preMask, k, n))) continue;
            else if (i > n && !bm & (1 << i - n >> 1)) continue;
 
            for (j = 1; j<= lc; j++) {
                if (j == i || !distance[preMask][j]) continue;
 
                tmp = distance[preMask][j] + m[j][i];
                if (!distance[bm][i]) distance[bm][i] = tmp;
                else distance[bm][i] = (distance[bm][i] < tmp? distance[bm][i] : tmp);
            }
        }
    }
 
    allMask--;
    unsigned int ans = distance[allMask][n + 1] + m[1][0];
    for (i = n + 2; i <= lc; i++) {
        if (!distance[allMask][i]) continue;
        tmp = distance[allMask][i] + m[i][0];
        ans = (ans < tmp ? ans : tmp);
    }
    cout << ans;
}