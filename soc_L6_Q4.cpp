#include <iostream>
#include <cmath>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* buildTree() {
    int val;
    cin >> val;
    if (val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    cout << "Enter left subtree for " << val << " (-1 for null):" << endl;
    root->left = buildTree();
    cout << "Enter right subtree for " << val << " (-1 for null):" << endl;
    root->right = buildTree();
    return root;
}
int getHeight(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}
bool isHeightBalanced(TreeNode* root) {
    if (root == nullptr)
        return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) <= 1 &&
        isHeightBalanced(root->left) && isHeightBalanced(root->right))
        return true;
    return false;
}

int main() {
    TreeNode* root = buildTree();
    if (isHeightBalanced(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

