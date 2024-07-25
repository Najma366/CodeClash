#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n) {
    if (i < n) {
        TreeNode* temp = newNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void findPaths(TreeNode* node, vector<int>& path, vector<vector<int>>& paths) {
    if (node == NULL) return;

    path.push_back(node->val);

    if (node->left == NULL && node->right == NULL) {
        paths.push_back(path);
    } else {
        
        findPaths(node->left, path, paths);
        findPaths(node->right, path, paths);
    }

    path.pop_back();
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int arr[n];
    cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    TreeNode* root = insertLevelOrder(arr, root, 0, n);

    vector<vector<int>> paths;
    vector<int> path;
    findPaths(root, path, paths);

    cout << "All paths from root to leaf nodes are:" << endl;
    for (const auto& p : paths) {
        printVector(p);
    }
}
