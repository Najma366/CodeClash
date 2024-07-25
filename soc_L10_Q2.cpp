#include <iostream>
#include <vector>
using namespace std;

bool dfs(int course, vector<vector<int>>& adjList, vector<int>& visited) {
    if (visited[course] == 1) return false; 
    if (visited[course] == 2) return true;  

    visited[course] = 1; 
    for (int nextCourse : adjList[course]) {
        if (!dfs(nextCourse, adjList, visited)) return false;
    }
    visited[course] = 2; 
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);
    for (auto& pre : prerequisites) {
        adjList[pre[1]].push_back(pre[0]);
    }

    vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
    for (int i = 0; i < numCourses; ++i) {
        if (!dfs(i, adjList, visited)) return false;
    }
    return true;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    int numPrerequisites;
    cout << "Enter the number of prerequisites: ";
    cin >> numPrerequisites;

    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    cout << "Enter the prerequisites (format: ai bi):" << endl;
    for (int i = 0; i < numPrerequisites; ++i) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    bool result = canFinish(numCourses, prerequisites);
    if (result) {
        cout << "Yes, you can finish all courses." << endl;
    } else {
        cout << "No, you cannot finish all courses." << endl;
    }
}
