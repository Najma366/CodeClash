#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthSmallest(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;
    for (int num : arr) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << "Enter the value of k: ";
    cin >> k;
    
    int result = findKthSmallest(arr, k);
    cout << "The " << k << "th smallest element is " << result << endl;
}
