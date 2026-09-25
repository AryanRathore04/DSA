// Leetcode 124: Binary Tree Maximum Path Sum
// Time Complexity: O(n), where n is the number of nodes in the tree 
// Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

// Approach:
// 1. We define a helper function `maxPathDown` that computes the maximum path sum starting from the current node and going downwards.
// 2. For each node, we calculate the maximum path sum of its left and right subtrees. If the maximum path sum of a subtree is negative, we consider it as 0 (i.e., we do not include that subtree in the path).
// 3. We update the global maximum path sum (`maxi`) by considering the sum of the current node's value and the maximum path sums from both left and right subtrees.
// 4. Finally, we return the maximum path sum found during the traversal of the tree.

#include <iostream>
#include <algorithm>
#include <climits>
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
    int maxPathSum(TreeNode* root){
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }

    private:
    int maxPathDown(TreeNode* node, int &maxi){
        if(node == nullptr) return 0;

        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));

        maxi = max(maxi, left + right + node->val);
        return max(left, right) + node->val;
    }
};