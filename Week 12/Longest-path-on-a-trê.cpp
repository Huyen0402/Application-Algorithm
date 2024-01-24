#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adjList;
vector<bool> visited;
int maxLength;

void dfs(int node, int length) {
    visited[node] = true;
    maxLength = max(maxLength, length);

    for (int i = 0; i < adjList[node].size(); i++) {
        int nextNode = adjList[node][i];
        if (!visited[nextNode]) {
            dfs(nextNode, length + 1);
        }
    }

    visited[node] = false; // Ðánh d?u l?i node dã du?c tham d? backtrack
}

int findLongestPath(int n, vector<pair<int, int> >& edges) {
    adjList.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    maxLength = 0;
    dfs(1, 0);

    return maxLength;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }

    int longestPathLength = findLongestPath(n, edges);
    cout << longestPathLength << endl;

    return 0;
}
