#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
    visited[node] = true;
    for (int i = 0; i < isConnected.size(); ++i) {
        if (isConnected[node][i] == 1 && !visited[i]) {
            dfs(i, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int provinces = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, isConnected, visited);
            ++provinces;
        }
    }
    
    return provinces;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    
    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> isConnected[i][j];
        }
    }
    
    int provinces = findCircleNum(isConnected);
    cout << "Total number of provinces: " << provinces << endl;
}
