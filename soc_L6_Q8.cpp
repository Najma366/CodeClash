#include <iostream>
#include <map>
#include <queue>
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

void topView(TreeNode* root) {
    if (root == NULL) return;

    map<int, int> topViewMap;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int hd = p.second;

        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->val;
        }

        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    for (auto it : topViewMap) {
        cout << it.second << " ";
    }
    cout << endl;
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
    cout << "Top view of the given binary tree is: ";
    topView(root);
}
