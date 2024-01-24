#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int> > pq;
    string cmd;
    int e;

    do {
        cin >> cmd;

        if (cmd == "PUSH") {
            cin >> e;
            pq.push(e);
        } else if (cmd == "POP") {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    } while (cmd != "#");

    return 0;
}
