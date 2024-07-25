#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform level order traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);

            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }

        result.push_back(currentLevel);
    }

    return result;
}

// Helper function to insert nodes in the tree
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

// Helper function to build the tree from input
TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty()) return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    int n, val;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> nodes(n);
    cout << "Enter the values of the nodes (-1 for null): ";
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);
    vector<vector<int>> result = levelOrder(root);

    cout << "Level Order Traversal of the binary tree: {";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "{";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "}";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}
