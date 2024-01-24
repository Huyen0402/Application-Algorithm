#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to check if a sequence is a feasible route
bool isFeasibleRoute(const vector<int>& sequence, const vector<pair<int, int> >& precedenceConstraints) {
    int n = sequence.size();

    // Create a mapping of point indices
    vector<int> pointIndex(n + 1);
    for (int i = 0; i < n; i++) {
        pointIndex[sequence[i]] = i;
    }

    // Check the precedence constraints
    for (const auto& constraint : precedenceConstraints) {
        int i = pointIndex[constraint.first];
        int j = pointIndex[constraint.second];
        if (i > j) {
            return false;
        }
    }

    return true;
}

// Function to compute the total travel distance of a route
int computeTotalTravelDistance(const vector<vector<int>>& distanceMatrix, const vector<int>& sequence) {
    int n = sequence.size();
    int totalDistance = 0;

    for (int i = 0; i < n - 1; i++) {
        int from = sequence[i];
        int to = sequence[i + 1];
        totalDistance += distanceMatrix[from - 1][to - 1];
    }

    // Add the distance from the last point back to the starting point
    int lastPoint = sequence[n - 1];
    int startingPoint = sequence[0];
    totalDistance += distanceMatrix[lastPoint - 1][startingPoint - 1];

    return totalDistance;
}

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    vector<vector<int>> distanceMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distanceMatrix[i][j];
        }
    }

    int m;
    cin >> m;

    vector<pair<int, int>> precedenceConstraints(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        precedenceConstraints[i] = make_pair(a, b);
    }

    // Check if the sequence is a feasible route
    bool isFeasible = isFeasibleRoute(sequence, precedenceConstraints);

    if (isFeasible) {
        // Compute the total travel distance
        int totalDistance = computeTotalTravelDistance(distanceMatrix, sequence);
        cout << totalDistance << endl;
    }
    else {
        cout << "-1" << endl;
    }

    return 0;
}

