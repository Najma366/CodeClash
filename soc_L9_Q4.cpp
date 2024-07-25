#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> ppi;

vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
    priority_queue<ppi, vector<ppi>, greater<ppi>> minHeap;
    
    for (int i = 0; i < k; i++) {
        minHeap.push({arr[i][0], {i, 0}});
    }
    
    vector<int> result;
    
    while (!minHeap.empty()) {
        ppi curr = minHeap.top();
        minHeap.pop();
        
        int val = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;
        
        result.push_back(val);
        
        if (y + 1 < arr[x].size()) {
            minHeap.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main() {
    int k;
    cout << "Enter the number of arrays (k): ";
    cin >> k;
    
    vector<vector<int>> arr(k, vector<int>(k));
    cout << "Enter the elements of the arrays:" << endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> arr[i][j];
        }
    }
    
    vector<int> result = mergeKSortedArrays(arr, k);
    
    cout << "The merged sorted array is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
