#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
using namespace std;

typedef pair<int, int> iPair;

void dijkstra(int V, vector<vector<iPair>>& adj, int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex Distance from Source " << src << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<iPair>> adj(V);
    cout << "Enter the edges (format: u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(V, adj, src);
}
