#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define INF 1e8

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> dist(V, vector<int>(V, INF));
    cout << "Enter the adjacency matrix (use -1 for no edge):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != -1) {
                dist[i][j] = weight;
            }
            if (i == j) {
                dist[i][j] = 0;
            }
        }
    }

    floydWarshall(dist, V);

    cout << "The shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "-1 ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}
