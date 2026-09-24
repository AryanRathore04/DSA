// Problem: Check for Balanced Binary Tree
// Time Complexity: O(n), where n is the number of nodes in the tree. We visit each node once.
// Space Complexity: O(h), where h is the height of the tree. This space is used by the recursion stack.

// Approach:
// 1. We define a helper function `dfsHeight` that computes the height of the tree and checks if it is balanced at the same time.
// 2. If the subtree is balanced, `dfsHeight` returns its height. If it is not balanced, it returns -1.
// 3. In the `isBalanced` function, we call `dfsHeight` on the root. If the result is -1, the tree is not balanced; otherwise, it is balanced.

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    bool isBalanced(TreeNode* root){
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }
};


int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}