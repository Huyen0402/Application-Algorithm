#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> pq;
    string cmd;
    int e;

    do {
        cin >> cmd;

        if (cmd == "PUSH") {
            cin >> e;
            pq.push_back(e);
            push_heap(pq.begin(), pq.end(), greater<int>());
        } else if (cmd == "POP") {
            if (!pq.empty()) {
                pop_heap(pq.begin(), pq.end(), greater<int>());
                int top = pq.back();
                pq.pop_back();
                cout << top << '\n';
            }
        }
    } while (cmd != "#");

    return 0;
}
