#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; ++i) {
        while (!s.empty() && (i == n || heights[s.top()] > heights[i])) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}

int main() {
    int n;
    cout << "Enter the number of bars in the histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int maxArea = largestRectangleArea(heights);
    cout << "The area of the largest rectangle is: " << maxArea << " units." << endl;
}
