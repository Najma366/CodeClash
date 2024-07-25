#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}

TreeNode* insertNode(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

int main() {
    TreeNode* root = NULL;
    int n, val;
    
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insertNode(root, val);
    }
    
    if (isValidBST(root, LONG_LONG_MIN, LONG_LONG_MAX)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }
}
