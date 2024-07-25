#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int findCeil(Node* root, int X) {
    int ceil = -1;
    while (root) {
        if (root->data == X) {
            ceil = root->data;
            break;
        }
        if (root->data < X) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int main() {
    int n, X;
    cout << "Enter the number of nodes in the BST: ";
    cin >> n;
    
    Node* root = nullptr;
    cout << "Enter the nodes of the BST: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    
    cout << "Enter the value of X: ";
    cin >> X;
    
    int ceil = findCeil(root, X);
    if (ceil == -1) {
        cout << "Ceil of " << X << " not found in the BST." << endl;
    } else {
        cout << "Ceil of " << X << " is " << ceil << "." << endl;
    }
}
