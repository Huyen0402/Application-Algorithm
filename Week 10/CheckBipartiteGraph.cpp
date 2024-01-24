#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int> >& graph, int N) {
    vector<int> colors(N+1, 0);

    for (int i = 1; i <= N; i++) {
        if (colors[i] == 0) {
            queue<int> q;
            q.push(i);
            colors[i] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int j = 0; j < graph[node].size(); j++) {
                    int neighbor = graph[node][j];

                    if (colors[neighbor] == colors[node]) {
                        return false;
                    }
                    if (colors[neighbor] == 0) {
                        colors[neighbor] = -colors[node];
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int> > graph(N+1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool result = isBipartite(graph, N);
    cout << result << endl;

    return 0;
}
