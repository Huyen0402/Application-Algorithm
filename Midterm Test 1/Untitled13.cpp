#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int H = 100;

int N, M;
int c[H];
int A[H][H];
int load[H];
vector<int> x;
int res;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
}

bool check(int v, int k) {
    for (int i = 1; i <= k - 1; i++) {
        if (A[i][k] == 1 && x[i] > v) {
            return false;
        }
    }

    return true;
}

void solution() {
    int maxLoad = *max_element(load + 1, load + M + 1);
    if (maxLoad < res) res = maxLoad;
}

void Try(int k) {
    for (int v = 1; v <= M; v++) {
        if (check(v, k)) {
            x[k] = v;
            load[v] += c[k];

            if (k == N) solution();
            else Try(k + 1);

            load[v] -= c[k];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();

    x.resize(N + 1);
    for (int i = 1; i <= M; i++) load[i] = 0;

    res = INT_MAX;
    Try(1);
    cout << res;

    return 0;
}
