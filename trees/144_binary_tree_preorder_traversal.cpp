// Leetcode 144. Binary Tree Preorder Traversal
// Given the root of a binary tree, return the preorder traversal of its nodes' values.
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(h), where h is the height of the binary tree (due to

// Approach: The pre-order traversal of a binary tree visits the nodes in the following order:
// 1. Visit the root node
// 2. Traverse the left subtree
// 3. Traverse the right subtree

#include <vector>
#include <iostream>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;


    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    void preorder(TreeNode* root, vector<int>& result){

        if(root == nullptr){
            return;
        }

        result.push_back(root->val);

        preorder(root->left, result);

        preorder(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> result;

        preorder(root, result);

        return result;
    }
};

