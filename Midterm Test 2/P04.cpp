#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 1e9+7

// Function to calculate the minimum travel distance using the Held-Karp algorithm
vector<int> calculateMinTravelDistance(vector<vector<int> >& distanceMatrix) {
    int n = distanceMatrix.size();
    int maxMask = (1 << n) - 1;

    // Initialize the DP table
    vector<vector<int> > dp(n, vector<int>(1 << n, MAX));
    vector<vector<int> > parent(n, vector<int>(1 << n, -1));

    // Base case: distance from starting point to itself is 0
    dp[0][1] = 0;

    // Calculate the optimal cost for each subset of cities
    for (int mask = 1; mask <= maxMask; mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) != 0 && j != i) {
                        int prevMask = mask ^ (1 << i);

                        if (dp[i][mask] > dp[j][prevMask] + distanceMatrix[j][i]) {
                            dp[i][mask] = dp[j][prevMask] + distanceMatrix[j][i];
                            parent[i][mask] = j;
                        }
                    }
                }
            }
        }
    }

    // Find the optimal path
    int mask = (1 << n) - 1;
    int lastCity = 0;
    int minDistance = MAX;

    for (int i = 0; i < n; i++) {
        if (dp[i][mask] + distanceMatrix[i][0] < minDistance) {
            minDistance = dp[i][mask] + distanceMatrix[i][0];
            lastCity = i;
        }
    }

    // Reconstruct the itinerary
    vector<int> itinerary;
    int currCity = lastCity;
    int currMask = mask;

    while (currCity != -1) {
        itinerary.push_back(currCity + 1);
        int prevCity = parent[currCity][currMask];
        currMask ^= (1 << currCity);
        currCity = prevCity;
    }

    reverse(itinerary.begin(), itinerary.end());

    return itinerary;
}

int main() {
    int n;
    cin >> n;

    // Read the distance matrix
    vector<vector<int> > distanceMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distanceMatrix[i][j];
        }
    }

    // Calculate the minimum travel distance
    vector<int> itinerary = calculateMinTravelDistance(distanceMatrix);

    // Add city 1 at the end to complete the loop
    itinerary.push_back(1);

    // Print the result
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << itinerary[i] << " ";
    }
    cout << endl;

    return 0;
}
