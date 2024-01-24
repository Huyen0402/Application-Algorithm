#include <iostream>

const int H = 100;

int N, M;
int c[H];
int A[H][H];
int load[H];
bool done[H];
int x[H];
int res;

void input(int& N, int& M, int c[], int A[][H]) {
    std::cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        std::cin >> c[i];
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            std::cin >> A[i][j];
        }
    }
}

bool check(int v, int k, bool done[], int A[][H]) {
    if(done[k]) return false;
    for(int i = 1; i <= N; i++) {
        if(A[v][i] == 1) {
            if(!done[i]) return false;
        }
    }
    
    return true;
}

void solution(int load[], int M, int& res) {
    int maxLoad = 0;
    for(int i = 1; i <= M; i++) {
        maxLoad = (load[i] > maxLoad) ? load[i] : maxLoad;
    }
    if(maxLoad < res) res = maxLoad;
}

void Try(int k, int load[], bool done[], int c[], int A[][H], int M, int& res) {
    for(int v = 1; v <= M; v++) {
        if(check(v, k, done, A)) {
            x[k] = v;
            load[v] += c[k];
            done[k] = true;
            if(k == N) solution(load, M, res);
            else Try(k + 1, load, done, c, A, M, res);
            load[v] = load[v] - c[k];
            done[k] = false;
        }
    }
    
}

int main() {
    input(N, M, c, A);
    
    for(int i = 1; i <= N; i++) done[i] = false;
    for(int i = 1; i <= M; i++) load[i] = 0;
    
    res = 1e9;
    Try(1, load, done, c, A, M, res);
    std::cout << res;
    
    return 0;
}
