#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stack;
    for (int asteroid : asteroids) {
        bool destroyed = false;
        while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
            if (stack.back() < -asteroid) {
                stack.pop_back();
                continue;
            } else if (stack.back() == -asteroid) {
                stack.pop_back();
            }
            destroyed = true;
            break;
        }
        if (!destroyed) {
            stack.push_back(asteroid);
        }
    }
    return stack;
}

int main() {
    int n;
    cout << "Enter the number of asteroids: ";
    cin >> n;

    vector<int> asteroids(n);
    cout << "Enter the asteroids: ";
    for (int i = 0; i < n; ++i) {
        cin >> asteroids[i];
    }
    vector<int> result = asteroidCollision(asteroids);

    cout << "The state of the asteroids after all collisions is: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;
}
