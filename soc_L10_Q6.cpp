#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (dist[u] != 1e8 && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if (dist[u] != 1e8 && dist[u] + weight < dist[v]) {
            return vector<int>(V, -1); // Negative cycle detected
        }
    }

    return dist;
}

int main() {
    int V, E, S;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    cout << "Enter the edges (format: u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "Enter the source vertex: ";
    cin >> S;

    vector<int> distances = bellmanFord(V, edges, S);

    if (distances[0] == -1) {
        cout << "Graph contains a negative weight cycle." << endl;
    } else {
        cout << "Vertex Distance from Source " << S << endl;
        for (int i = 0; i < V; ++i) {
            cout << i << "\t\t" << distances[i] << endl;
        }
    }
}
