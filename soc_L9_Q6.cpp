#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, pair<int, int>> ppi;

vector<int> maxKSumCombinations(vector<int>& A, vector<int>& B, int K) {
    int N = A.size();
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    priority_queue<ppi> maxHeap;
    set<pair<int, int>> mySet;
    
    maxHeap.push({A[0] + B[0], {0, 0}});
    mySet.insert({0, 0});
    
    vector<int> result;
    
    for (int count = 0; count < K; ++count) {
        ppi curr = maxHeap.top();
        maxHeap.pop();
        
        result.push_back(curr.first);
        
        int i = curr.second.first;
        int j = curr.second.second;
        
        if (i + 1 < N && mySet.find({i + 1, j}) == mySet.end()) {
            maxHeap.push({A[i + 1] + B[j], {i + 1, j}});
            mySet.insert({i + 1, j});
        }
        
        if (j + 1 < N && mySet.find({i, j + 1}) == mySet.end()) {
            maxHeap.push({A[i] + B[j + 1], {i, j + 1}});
            mySet.insert({i, j + 1});
        }
    }
    return result;
}

int main() {
    int N, K;
    cout << "Enter the size of the arrays (N): ";
    cin >> N;
    
    vector<int> A(N), B(N);
    cout << "Enter the elements of array A: ";
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    cout << "Enter the elements of array B: ";
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    cout << "Enter the value of K: ";
    cin >> K;
    
    vector<int> result = maxKSumCombinations(A, B, K);
    
    cout << "The maximum " << K << " valid sum combinations are: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
}
