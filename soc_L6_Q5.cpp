#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* node, int& diameter) {
    if (node == NULL) return 0;
    int leftHeight = height(node->left, diameter);
    int rightHeight = height(node->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
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
    cout << "Diameter of the given binary tree is " << diameterOfBinaryTree(root) << endl;
}
