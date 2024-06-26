#include <iostream>
#include<vector>
#include<queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void iterativePreorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        TreeNode* current = nodeStack.top();
        nodeStack.pop();
        cout << current->val << " "; 
        if (current->right) {
            nodeStack.push(current->right);
        }
        if (current->left) {
            nodeStack.push(current->left);
        }
    }
}
TreeNode* createTreeFromInput() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    queue<TreeNode*> nodeQueue;
    TreeNode* root = new TreeNode(values[0]);
    nodeQueue.push(root);
    for (int i = 1; i < n; ++i) {
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();
        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            nodeQueue.push(current->left);
        }
        ++i;
        if (i < n && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            nodeQueue.push(current->right);
        }
    }
    return root;
}
int main() {
    TreeNode* root = createTreeFromInput();
    iterativePreorder(root);
}

