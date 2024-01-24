#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int n;
typedef pair <int, int> ii;

ii Seg[N];

int result;

bool cmp(ii X, ii Y) {     
    return (X.second < Y.second); 
} 

void solve() {
    sort(Seg+1,Seg+n+1,cmp);

    int lastSecond = -1e9;
    result = 0; 
    for(int i = 1; i <= n; i++) { // kiem tra xem doan i co giao voi doan cuoi cung cua buoc truoc hay khong
        if(Seg[i].first > lastSecond) {
            result++;
            lastSecond = Seg[i].second;
        }
    }

    cout << result << "\n";
}

int main() {
    cin >> n;
    for(int i = 1; i<=n; i++) {
        cin >> Seg[i].first >> Seg[i].second;
    }
    solve();
    
    return 0;
}