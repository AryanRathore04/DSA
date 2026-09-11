// Leetcode Problem: 94. Binary Tree Inorder Traversal
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(h), where h is the height of the binary tree (due to

// Approach: The in-order traversal of a binary tree visits the nodes in the following order:
// 1. Traverse the left subtree
// 2. Visit the root node
// 3. Traverse the right subtree

#include <vector>
using namespace std;

 // Definition for a binary tree node.
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
    void inorder(TreeNode* root, vector<int>& result){
        if(root == nullptr){
            return;
        }

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        inorder(root, result);
        return result;
    }
};