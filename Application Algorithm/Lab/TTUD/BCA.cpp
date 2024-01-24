#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> preferring_teachers;
vector<int> conflict_courses;
vector<vector<bool>> available_teachers;
vector<int> loads;
int m, n, ans = INT32_MAX;
bool solved = false;

vector<int> track;

void tryCourse(int i) {
    if (i == n) {
        int max_load = 0;
        for (int load : loads) {
            max_load = max(load, max_load);
        }

        solved = true;
        ans = min(ans, max_load);

        return;
    }

    for (int teacher : preferring_teachers[i]) {
        if (!available_teachers[i][teacher]) {
            continue;
        }
        if (solved && loads[teacher] >= ans) {
            continue;
        }

        available_teachers[i][teacher] = false;
        if (conflict_courses[i] != -1) {
            available_teachers[conflict_courses[i]][teacher] = false;
        }
        loads[teacher]++;

        track[i] = teacher;

        if (loads[teacher] < ans) {
            tryCourse(i + 1);
        }

        available_teachers[i][teacher] = true;
        if (conflict_courses[i] != -1) {
            available_teachers[conflict_courses[i]][teacher] = true;
        }
        loads[teacher]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    loads.resize(m, 0);
    preferring_teachers.resize(n);
    track.resize(n);
    conflict_courses.resize(n, -1);
    available_teachers.resize(n, vector<bool>(m, true));
    int k, c, c1;
    for (int i = 0; i < m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> c;
            c--;
            preferring_teachers[c].push_back(i);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> c >> c1;
        c--;
        c1--;
        conflict_courses[c] = c1;
        conflict_courses[c1] = c;
    }

    tryCourse(0);

    if (solved) {
        cout << ans;
    } else {
        cout << -1;
    }
}