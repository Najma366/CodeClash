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

// Function to find the maximum depth of the binary tree
int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
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
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> nodes(n);
    cout << "Enter the values of the nodes (-1 for null): ";
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);
    int depth = maxDepth(root);

    cout << "The maximum depth of the binary tree is: " << depth << endl;
}
