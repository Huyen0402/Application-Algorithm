#include <bits/stdc++.h>

using namespace std;
const int N = 100;
int n, Q;
int d[N][N];

int x[N];
int f, f_best;
int load;

bool visited[N];
int d_min;

void input() {
    cin >> n >> Q;
    d_min = 1e9;
    for(int i = 0; i <= 2*n; i++) {
        for(int j = 0; j <= 2*n; j++) {
            cin >> d[i][j];
            if((i != j) && (d[i][j] < d_min)) d_min = d[i][j];
        }
    }
}

bool check(int v, int k) {
    if(visited[v]) return false;
    if(v <= n) { // v la diem don
        if(load >= Q) return false;
    } else { // v la diem tra
        if(!visited[v-n]) return false;
    }

    return true;
}

void updateBest() {
    if(f + d[x[2*n]][x[0]] < f_best) {
        f_best = f + d[x[2*n]][x[0]];
    } 
}

void Try(int k) {
     for(int v = 1; v <= 2*n; v++) {
        if(check(v, k)) {
            x[k] = v;
            f = f + d[x[k-1]][x[k]];
            if(v <= n) load += 1; else load -= 1;
            visited[v] = true;
            if(k == 2*n) updateBest();
            else {
                if(f + d_min*(2*n-k+1) < f_best)
                    Try(k+1);
            }

            visited[v] = false;
            if(v <= n) load -= 1; else load += 1;
            f = f - d[x[k-1]][x[k]];
        }
     }
}


int main() {
    input();
    for(int v = 1; v <= 2*n; v++) visited[v] = false;
    f = 0; 
    load = 0;
    f_best = 1e9;
    x[0] = 0;
    Try(1);
    cout << f_best << "\n";

    return 0;
}