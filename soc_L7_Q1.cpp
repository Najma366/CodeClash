#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> ngeMap;
    stack<int> s;

    for (int num : nums2) {
        while (!s.empty() && s.top() < num) {
            ngeMap[s.top()] = num;
            s.pop();
        }
        s.push(num);
    }

    while (!s.empty()) {
        ngeMap[s.top()] = -1;
        s.pop();
    }
    vector<int> result;
    for (int num : nums1) {
        result.push_back(ngeMap[num]);
    }
    return result;
}

int main() {
    int n1, n2, val;
    cout << "Enter the number of elements in nums1: ";
    cin >> n1;
    cout << "Enter the number of elements in nums2: ";
    cin >> n2;

    vector<int> nums1(n1), nums2(n2);

    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }

    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < n2; ++i) {
        cin >> nums2[i];
    }

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "The next greater elements are: ";
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;
}
