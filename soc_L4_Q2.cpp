#include <iostream>
#include <vector>
using namespace std;

long merge(vector<int>& arr, vector<int>& left, vector<int>& right) {
    int i = 0, j = 0;
    long count = 0;
    while (i < left.size() || j < right.size()) {
        if (i == left.size()) {
            arr[i + j] = right[j];
            j++;
        } else if (j == right.size()) {
            arr[i + j] = left[i];
            i++;
        } else if (left[i] <= right[j]) {
            arr[i + j] = left[i];
            i++;
        } else {
            arr[i + j] = right[j];
            count += left.size() - i;
            j++;
        }
    }
    return count;
}
long invCount(vector<int>& arr) {
    if (arr.size() < 2) return 0;
    int m = (arr.size() + 1) / 2;
    vector<int> left(arr.begin(), arr.begin() + m);
    vector<int> right(arr.begin() + m, arr.end());
    return invCount(left) + invCount(right) + merge(arr, left, right);
}

int main() {
    int N; 
    cin >> N;
    vector<int> ARR(N);
    for (int i = 0; i < N; ++i) {
        cin >> ARR[i];
    }
    long totalInversions = invCount(ARR);
    cout << totalInversions << endl;
}
