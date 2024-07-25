#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSumUtil(TreeNode* node, int& maxSum) {
    if (node == NULL) return 0;

    int leftSum = max(0, maxPathSumUtil(node->left, maxSum));
    int rightSum = max(0, maxPathSumUtil(node->right, maxSum));

    int currentSum = node->val + leftSum + rightSum;
    maxSum = max(maxSum, currentSum);

    return node->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
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
    cout << "Maximum path sum of the given binary tree is " << maxPathSum(root) << endl;
}
