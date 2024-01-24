#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;

    while (N != 0) {
        if (N >= 5) {
            N -= 5;
        } else if (N <= 10000) {
            N += 2;
        }
        count++;
    }

    cout << count << endl;

    return 0;
}
