#include <bits/stdc++.h>

using namespace std;

int n;
int M[30][1000000];
int A[1000000];

void preprocessing() {
    for(int j = 0; (1 << j) <= n; j++) {
        for(int i = 0; i < n; i++) {
            M[j][i] = -1;
        }
    }
    for(int i = 0; i < n; i++) {
        M[0][i] = i;
    }
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; i + (1 << j) - 1 < n; i++) {
            if(A[M[j-1][i]] < A[M[j-1][i + (1 << (j-1))]])
                M[j][i] = M[j-1][i];
            else M[j][i] = M[j-1][i + (1 << (j-1))];
        }
    }
}

// void display(int n) {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cout << M[i][j] << "\t";
//         }
//         cout << endl;
//     }
// }

int rmq(int i, int j) {
    int k = log2(j-i+1);
    int p2k = (1 << k); //pow(2, k)
    if(A[M[k][i]] < A[M[k][j-p2k+1]]) {
        return M[k][i];
    } else {
        return M[k][j-p2k+1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    preprocessing();
    // display(n);
    
    int ans = 0; int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int I, J;
        cin >> I >> J;
        ans += A[rmq(I, J)];
    }

    cout << ans;

    return 0;
}

