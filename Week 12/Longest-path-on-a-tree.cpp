#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int> > > adjList;
vector<bool> visited;
int maxLength;

void dfs(int node, int length) {
    visited[node] = true;
    
    if (length > maxLength) {
        maxLength = length;
    }

    for (int i = 0; i < adjList[node].size(); i++) {
        int nextNode = adjList[node][i].first;
        int edgeWeight = adjList[node][i].second;
        if (!visited[nextNode]) {
            dfs(nextNode, length + edgeWeight);
        }
    }

    visited[node] = false; // ��nh d?u l?i node d� du?c tham d? backtrack
}

int findLongestPath(int n, int startNode) {
    visited.resize(n + 1, false);
    maxLength = 0;

    dfs(startNode, 0);

    return maxLength;
}

int main() {
    int n;
    cin >> n;

    adjList.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    int startNode = 1; // Ch?n d?nh b?t k? l�m d?nh g?c (startNode)
    int longestPath = findLongestPath(n, startNode); // T�m d? d�i c?a du?ng di d�i nh?t tr�n c�y

    cout << longestPath << endl;

    return 0;
}
