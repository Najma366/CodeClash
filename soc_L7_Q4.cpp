#include <iostream>
#include <string>
#include <stack>
using namespace std;

string removeKdigits(string num, int k) {
    int n = num.size();
    stack<char> s;

    for (char c : num) {
        while (!s.empty() && k > 0 && s.top() > c) {
            s.pop();
            k--;
        }
        s.push(c);
    }

    while (k > 0) {
        s.pop();
        k--;
    }

    string result = "";
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }

    int start = 0;
    while (start < result.size() && result[start] == '0') {
        start++;
    }

    result = result.substr(start);
    return result.empty() ? "0" : result;
}

int main() {
    string num;
    int k;

    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the value of k: ";
    cin >> k;

    string result = removeKdigits(num, k);
    cout << "The smallest possible integer after removing " << k << " digits is: " << result << endl;
}
