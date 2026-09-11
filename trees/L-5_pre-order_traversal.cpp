// Program to perform pre-order traversal of a binary tree
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(h), where h is the height of the binary tree (due to recursion stack)

// Approach: The pre-order traversal of a binary tree visits the nodes in the following order:
// 1. Visit the root node
// 2. Traverse the left subtree
// 3. Traverse the right subtree

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

  cout << root->data << " "; // Visit the root node
    preOrderTraversal(root->left);  // Traverse the left subtree
    preOrderTraversal(root->right); // Traverse the right subtree
}


int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // Clean up memory (delete nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}