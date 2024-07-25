#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else {
            if (stk.empty()) return false;
            char top = stk.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    if (isValid(s)) {
        cout << "The input string is valid." << endl;
    } else {
        cout << "The input string is not valid." << endl;
    }
}
