#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorderTraversal(Node* root, int& k, int& result) {
    if (root == nullptr || k <= 0) return;
    
    inorderTraversal(root->left, k, result);
    
    k--;
    if (k == 0) {
        result = root->data;
        return;
    }
    
    inorderTraversal(root->right, k, result);
}

int kthSmallest(Node* root, int k) {
    int result = -1;
    inorderTraversal(root, k, result);
    return result;
}

int main() {
    int n, k;
    cout << "Enter the number of nodes in the BST: ";
    cin >> n;
    
    Node* root = nullptr;
    cout << "Enter the nodes of the BST: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    
    cout << "Enter the value of k: ";
    cin >> k;
    
    int result = kthSmallest(root, k);
    if (result == -1) {
        cout << "There are less than " << k << " nodes in the BST." << endl;
    } else {
        cout << "The " << k << "th smallest element is " << result << "." << endl;
    }
}
