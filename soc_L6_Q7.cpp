#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            int index = leftToRight ? i : size - 1 - i;
            level[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        leftToRight = !leftToRight;
        result.push_back(level);
    }
    return result;
}

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
    vector<vector<int>> result = zigzagLevelOrder(root);
    cout << "Zigzag Level Order Traversal: [";
    for (const auto& level : result) {
        cout << "[";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}
