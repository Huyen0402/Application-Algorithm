#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 +2;
int n, m, CriticalEdge;
vector <int> a[N];
int Low[N], Num[N];
bool CriticalNode[N];
int Time = 0;



void inp() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void visit(int u, int p) {
    int NumChild = 0;
    Low[u] = Num[u] = ++ Time;
    for(int i = 0; i < int(a[u].size()); i++) {
        int v = a[u][i];
        if(v != p) {
            if(Num[v]) Low[u] = min(Low[u], Num[v]);
            else {
                visit(v, u);
                ++NumChild;
                Low[u] = min(Low[u], Low[v]);

                if(Low[v] >= Num[v]) ++CriticalEdge;

                if(u == p) {
                    if(NumChild >= 2) CriticalNode[u] = true;
                } else {
                    if(Low[v] >= Num[u]) CriticalNode[u] = true;
                }
            }
        }
    }
}

void proc() {
    for(int i = 1; i <= n; i++) if(!Num[i]) visit(i, i);
    int Count = 0;
    for(int i = 1; i <= n; i++) if(CriticalNode[i]) ++Count;
    cout << Count << " " << CriticalEdge << endl;
}


int main() {
    inp();
    proc();
    return 0;
}