// Leetcode 543. Diameter of Binary Tree
// Problem: Diameter of Binary Tree
// Time Complexity: O(n), where n is the number of nodes in the binary tree. We visit each node once.
// Space Complexity: O(h), where h is the height of the binary tree. This space is used by the recursion stack.

// Approach: We can use a depth-first search (DFS) approach to calculate the height of each subtree and update the diameter at each node. The diameter at a node is the sum of the heights of its left and right subtrees. We keep track of the maximum diameter found during the traversal.

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter){
        if(!node) return 0;

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};