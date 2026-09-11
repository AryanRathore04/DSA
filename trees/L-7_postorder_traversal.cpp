// Problem: Postorder Traversal of a Binary Tree
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(h), where h is the height of the binary tree (due to recursion stack)

// Approach: The post-order traversal of a binary tree visits the nodes in the following order:
// 1. Traverse the left subtree
// 2. Traverse the right subtree
// 3. Visit the root node

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    void postorder(Node* root, vector<int>& result){
        if(root == nullptr){
            return;
        }

        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->data);
    }

    vector<int> postorderTraversal(Node* root){
        vector<int> result;

        postorder(root, result);
        return result;
    }
};

int main() {
    // Create a binary tree for testing
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
    vector<int> result = solution.postorderTraversal(root);

    // Print the postorder traversal result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (delete nodes)
    delete root->left->left;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}