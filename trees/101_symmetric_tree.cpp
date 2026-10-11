// Leetcode Problem: 101. Symmetric Tree
// Time Complexity: O(n), where n is the number of nodes in the tree
// Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

// Approach: We can use a recursive approach to check if the left and right subtrees are mirror images of each other. We define a helper function isMirror that takes two nodes as input and checks if they are mirrors of each other. The base cases handle null nodes, and we recursively check the left and right children of the nodes.


#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isMirror(root->left, root->right); 
    }
private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};