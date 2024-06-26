#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum(int arr[], int size){
    int max_so_far = arr[0];
    int max_ending_here = arr[0];
    for (int i = 1; i < size; ++i){
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max(max_so_far, 0);
}

int main(){
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int totalMaxSum = maxSubarraySum(arr, n);
    cout << totalMaxSum << endl;
}

