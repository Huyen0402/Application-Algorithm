#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a node and its distance from the source
struct Node {
    int id;
    int distance;

    Node(int _id, int _distance) : id(_id), distance(_distance) {}

    // Comparison operator for the priority queue
    bool operator<(const Node& other) const {
        return distance > other.distance;
    }
};

// Function to find the shortest path using Dijkstra's algorithm
int dijkstra(vector<vector<pair<int, int> > >& graph, int source, int target) {
    int n = graph.size();

    // Create a vector to store distances from the source node
    vector<int> dist(n, numeric_limits<int>::max());

    // Priority queue to store nodes and their distances
    priority_queue<Node> pq;

    // Initialize the distance of the source node and insert it into the priority queue
    dist[source] = 0;
    pq.push(Node(source, 0));

    while (!pq.empty()) {
        // Extract the node with the minimum distance
        Node node = pq.top();
        pq.pop();

        int u = node.id;
        int distance = node.distance;

        // If the extracted node is the target node, return its distance
        if (u == target) {
            return distance;
        }

        // Process all neighbors of the current node
        for (int j = 0; j < graph[u].size(); j++) {
    		int v = graph[u][j].first;
    		int weight = graph[u][j].second;

    		// Calculate the new distance to the neighbor node
    		int newDist = distance + weight;

    		// If the new distance is smaller, update the distance and insert the neighbor into the priority queue
    		if (newDist < dist[v]) {
        		dist[v] = newDist;
        		pq.push(Node(v, newDist));
    		}
		}
    }

    // If there is no path from the source to the target, return -1
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Create a vector of vectors to represent the graph
    vector<vector<pair<int, int> > > graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Add the edge to the graph
        graph[u - 1].push_back(make_pair(v - 1, w));
    }

    int source, target;
    cin >> source >> target;

    // Find the shortest path using Dijkstra's algorithm
    int shortestPath = dijkstra(graph, source - 1, target - 1);

    cout << shortestPath << endl;

    return 0;
}
