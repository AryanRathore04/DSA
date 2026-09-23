// Leetcode 104. Maximum Depth of Binary Tree
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree. This space is used by the recursion stack. In the worst case, the height of the tree can be n for a skewed tree, leading to O(n) space complexity. In the best case of a balanced tree, the height is log(n), leading to O(log(n)) space complexity.

// Approach: We can solve this problem using a recursive depth-first search (DFS) approach. The idea is to traverse the tree and calculate the depth of each subtree. The maximum depth of the tree will be the maximum depth of its left and right subtrees plus one for the current node.

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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh,rh);
    }
};