#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int n;

void insertX(int a[], int &n, int x){
    n++;
    
    a[n-1]=x;
}

int deleteMax(int a[], int n) {
    int i;
    int max_pos = 0;
    int max = a[0];
    // find max value and position's
    for(i = 1; i < n; i++)
    {
        if(max < a[i])
        {
            max = a[i];
            max_pos = i;
        }
    }
    cout << a[max_pos] << endl;
    for(i = max_pos; i < n; i++)
    {
        a[i] = a[i+1];
    }
    n--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int x;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    string prob;
    while(true) {
        cin >> prob;    
        if(prob == "*") break;

        if(prob == "insert") {
            cin >> x;
            insertX(a, n, x);
        }

        if(prob == "delete-max") {
            deleteMax(a, n);
        }
    }
}