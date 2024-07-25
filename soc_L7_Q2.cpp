#include <iostream>
#include <vector>
using namespace std;

int trapRainWater(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];

    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }
    int trappedWater = 0;
    for (int i = 0; i < n; ++i) {
        trappedWater += min(leftMax[i], rightMax[i]) - height[i];
    }
    return trappedWater;
}

int main() {
    int n;
    cout << "Enter the number of elements in the elevation map: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the elements of the elevation map: ";
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int result = trapRainWater(height);
    cout << "The amount of trapped water is: " << result << " units." << endl;
}
