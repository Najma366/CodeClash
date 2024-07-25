#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cutRod(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;
    
    vector<int> price(n);
    cout << "Enter the prices for each length: ";
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }
    
    int maxValue = cutRod(price, n);
    cout << "The maximum obtainable value is " << maxValue << endl;
}
