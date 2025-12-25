#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Computes shortest path using Dijkstra while skipping blocked locations
vector<int> computeShortestPath(
    int totalLocations,
    const vector<vector<pair<int,int>>> &graph,
    int source,
    int destination,
    const vector<bool> &blocked
) {
    vector<int> minDistance(totalLocations, INF);
    vector<int> parent(totalLocations, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    if (blocked[source] || blocked[destination]) return {};

    minDistance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        int currentDistance = top.first;
        int currentNode = top.second;
        pq.pop();

        // Ignore outdated entries
        if (currentDistance > minDistance[currentNode]) continue;

        for (const auto& edge : graph[currentNode]) {
            int neighbor = edge.first;
            int distance = edge.second;
            if (blocked[neighbor]) continue;

            if (minDistance[currentNode] + distance < minDistance[neighbor]) {
                minDistance[neighbor] = minDistance[currentNode] + distance;
                parent[neighbor] = currentNode;
                pq.push({minDistance[neighbor], neighbor});
            }
        }
    }

    if (minDistance[destination] == INF) return {};

    vector<int> path;
    for (int current = destination; current != -1; current = parent[current]) {
        path.push_back(current);
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    cout << endl << "Adaptive Route Optimizer using Graph Algorithms" << endl;
    cout << "---------------------------------------------" << endl << endl;

    int locations, roads;
    cout << "Enter number of locations (nodes): ";
    cin >> locations;

    cout << "Enter number of roads (edges): ";
    cin >> roads;

    vector<vector<pair<int,int>>> graph(locations);

    cout << endl << "Enter each road as: <from> <to> <distance>" << endl;
    cout << "Example: 0 1 5" << endl << endl;

    for (int i = 0; i < roads; i++) {
        int from, to, distance;
        cin >> from >> to >> distance;

        graph[from].push_back({to, distance});
        graph[to].push_back({from, distance}); // undirected
    }

    int blockedCount;
    cout << endl << "Enter number of blocked locations: ";
    cin >> blockedCount;

    vector<bool> blocked(locations, false);
    if (blockedCount > 0) {
        cout << "Enter blocked location indices:" << endl;
        for (int i = 0; i < blockedCount; i++) {
            int blockedLocation;
            cin >> blockedLocation;
            blocked[blockedLocation] = true;
        }
    }

    int source, destination;
    cout << endl << "Enter start location: ";
    cin >> source;

    cout << "Enter destination location: ";
    cin >> destination;

    vector<int> path = computeShortestPath(
        locations, graph, source, destination, blocked
    );

    cout << endl << "Result:" << endl;
    if (path.empty()) {
        cout << "No valid route found due to constraints." << endl;
    } else {
        cout << "Optimal route: ";
        for (int node : path) cout << node << " ";
        cout << endl;
    }

    return 0;
}