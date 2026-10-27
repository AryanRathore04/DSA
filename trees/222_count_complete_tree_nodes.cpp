// Problem: Count Complete Tree Nodes
// Time Complexity: O(log(n)^2)
// Space Complexity: O(log(n)) due to recursion stack

// Approach:
// 1. Calculate the height of the leftmost path (lh) and the rightmost path (rh) of the tree.
// 2. If lh == rh, then the tree is a perfect binary tree, and the number of nodes can be calculated using the formula 2^h - 1.
// 3. If lh != rh, then recursively count the nodes in the left and right subtrees and add 1 for the root node.
// 4. The recursion continues until the base case is reached (when the node is nullptr).

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if(lh == rh) return (1 << lh) - 1;

        return 1 + (countNodes(root->left)) + (countNodes(root->right));
    }

    int findHeightLeft(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }

    int findHeightRight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
};