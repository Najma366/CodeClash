#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0'; // mark as visited
    dfs(grid, i + 1, j); // down
    dfs(grid, i - 1, j); // up
    dfs(grid, i, j + 1); // right
    dfs(grid, i, j - 1); // left
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int num_islands = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == '1') {
                ++num_islands;
                dfs(grid, i, j);
            }
        }
    }
    return num_islands;
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    cout << "Enter the grid (0 for water, 1 for land):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;
}
