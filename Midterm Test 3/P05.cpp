#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; // S? lu?ng s?n ph?m v� s? lu?ng k? h�ng
vector<vector<int> > Q; // Ma tr?n s? lu?ng s?n ph?m trong t?ng k? h�ng
vector<vector<int> > d; // Ma tr?n kho?ng c�ch di chuy?n gi?a c�c k?
vector<int> q; // S? lu?ng s?n ph?m c?n l?y
vector<int> bestPath; // �u?ng di t?t nh?t
int minDistance = INT_MAX; // Gi� tr? kho?ng c�ch di chuy?n nh? nh?t

void DFS(int cur, int distance, vector<bool>& visited, vector<int>& path) {
    if (cur == 0 && path.size() == M) { // �� gh� tham t?t c? c�c k? h�ng v� quay l?i c?a
        if (distance < minDistance) { // Ki?m tra xem du?ng di n�y c� t?t hon du?ng di t?t nh?t hi?n t?i kh�ng
            minDistance = distance;
            bestPath = path;
        }
        return;
    }

    for (int i = 1; i <= M; i++) {
        if (!visited[i]) { // Ki?m tra xem k? h�ng i d� du?c gh� tham chua
            visited[i] = true;
            path.push_back(i);

            int nextDistance = distance + d[cur][i];
            vector<int> nextQ = q; // S? lu?ng s?n ph?m c?n l?y ? l?n gh� tham ti?p theo

            // Tr? s? lu?ng s?n ph?m d� l?y ? k? h�ng i kh?i s? lu?ng c?n l?y
            for (int j = 0; j < N; j++) {
                nextQ[j] -= Q[j][i];
                if (nextQ[j] < 0) { // Ki?m tra xem s? lu?ng s?n ph?m c?n l?y c� �m kh�ng
                    visited[i] = false;
                    path.pop_back();
                    return; // Kh�ng th?a m�n di?u ki?n, quay lui
                }
            }

            DFS(i, nextDistance, visited, path);

            visited[i] = false;
            path.pop_back();
            q = nextQ; // C?p nh?t s? lu?ng s?n ph?m c?n l?y
        }
    }
}

int main() {
    cin >> N >> M;

    Q.resize(N, vector<int>(M + 1)); // Ma tr?n Q c� k�ch thu?c N x (M+1)
    d.resize(M + 1, vector<int>(M + 1)); // Ma tr?n d c� k�ch thu?c (M+1) x (M+1)
    q.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> Q[i][j];
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> d[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> q[i];
    }

    vector<bool> visited(M + 1, false); // M?ng d�nh d?u k? h�ng d� du?c gh� tham
    vector<int> path; // �u?ng di hi?n t?i

    DFS(0, 0, visited, path);

    cout << bestPath.size() << endl;
    for (int i = 0; i < bestPath.size(); i++) {
        cout << bestPath[i] << " ";
    }

    return 0;
}
