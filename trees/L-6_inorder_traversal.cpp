// Problem: Given the root of a binary tree, return the inorder traversal of its nodes' values.
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(h), where h is the height of the binary tree (due to recursion stack)

// Approach: The in-order traversal of a binary tree visits the nodes in the following order:
// 1. Traverse the left subtree
// 2. Visit the root node
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

class Solution {
    public:
    void inorder(Node* root, vector<int>& result){
        if(root == nullptr){
            return;
        }

        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }

    vector<int> inorderTraversal(Node* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

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

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    cout << "In-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
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

