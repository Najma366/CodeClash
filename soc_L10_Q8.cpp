#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include<climits>
using namespace std;

typedef pair<int, int> iPair;

int primMST(int V, vector<vector<iPair>>& adj) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    int mstWeight = 0;

    pq.push(make_pair(0, 0));
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        mstWeight += key[u];

        for (auto& x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    return mstWeight;
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

    int mstWeight = primMST(V, adj);
    cout << "Sum of the weights of the edges in the Minimum Spanning Tree: " << mstWeight << endl;
}
