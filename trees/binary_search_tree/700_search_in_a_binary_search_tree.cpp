// Leetcode Problem 700: Search in a Binary Search Tree
// Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

// Time Complexity: O(h), where h is the height of the tree. In the average case, the height of a balanced BST is log(n), where n is the number of nodes in the tree. In the worst case, the height can be n (for a skewed tree).
// Space Complexity: O(1) for the iterative approach, as we are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the input tree.

// Approach: Create a function that takes the root of the BST and the value to search for. Use a while loop to traverse the tree. If the current node's value matches the target value, return the current node. If the target value is less than the current node's value, move to the left child; otherwise, move to the right child. Continue this process until you find the target value or reach a NULL node.

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val){
            root = val < root->val ? root->left : root->right;
        }

        return root;
    }
};