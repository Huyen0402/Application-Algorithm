#include <bits/stdc++.h>

using namespace std;

const int H = 100;

int N, M;
int c[H];
int A[H][H];
int minLoad[H];
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
    int maxLoad = *max_element(minLoad + 1, minLoad + M + 1);
    if (maxLoad < res) res = maxLoad;
}

void Try(int k) {
    for (int i = 1; i <= M; i++) {
        if (minLoad[i] + c[k] < res) {
            if (check(i, k)) {
                x[k] = i;
                minLoad[i] += c[k];

                if (k == N) solution();
                else Try(k + 1);

                minLoad[i] -= c[k];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();

    x.resize(N + 1);
    for (int i = 1; i <= M; i++) minLoad[i] = 0;

    sort(c + 1, c + N + 1, greater<int>());

    res = INT_MAX;
    Try(1);
    cout << res;

    return 0;
}
