#include <bits/stdc++.h>

using namespace std;
#define N 1000

struct State {
    int x;
    int y;
    int steps; // the number of steps performed for obtaining the current step from starting step (0,0)
    State(int a, int b, int s) : x(a), y(b), steps(s) {}
};

int minStepsToTarget(int a, int b, int target) {
    queue<State> q;
    bool visited[N][N];
    for(int i = 0; i < N; i++) {
    	for(int j = 0; j < N; j++) {
    		visited[i][j] = false;
		}
	}

    q.push(State(0, 0, 0));
    visited[0][0] = true;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.x == target || curr.y == target) {
            return curr.steps;
        }

        if (!visited[a][curr.y]) {
            q.push(State(a, curr.y, curr.steps + 1));
            visited[a][curr.y] = true;
        }

        if (!visited[curr.x][b]) {
            q.push(State(curr.x, b, curr.steps + 1));
            visited[curr.x][b] = true;
        }

        int pourAmount = min(b - curr.y, curr.x);
        if (!visited[curr.x - pourAmount][curr.y + pourAmount]) {
            q.push(State(curr.x - pourAmount, curr.y + pourAmount, curr.steps + 1));
            visited[curr.x - pourAmount][curr.y + pourAmount] = true;
        }

        pourAmount = min(a - curr.x, curr.y);
        if (!visited[curr.x + pourAmount][curr.y - pourAmount]) {
            q.push(State(curr.x + pourAmount, curr.y - pourAmount, curr.steps + 1));
            visited[curr.x + pourAmount][curr.y - pourAmount] = true;
        }

        if (!visited[0][curr.y]) {
            q.push(State(0, curr.y, curr.steps + 1));
            visited[0][curr.y] = true;
        }

        if (!visited[curr.x][0]) {
            q.push(State(curr.x, 0, curr.steps + 1));
            visited[curr.x][0] = true;
        }
    }

    return -1;
}

int main() {
    int a, b, target;
    cin >> a >> b >> target;

    int steps = minStepsToTarget(a, b, target);
    cout << steps << endl;

    return 0;
}
