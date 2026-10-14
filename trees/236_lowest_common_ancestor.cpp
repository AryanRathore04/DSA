// Leetcode 236. Lowest Common Ancestor of a Binary Tree
// Time Complexity: O(n), where n is the number of nodes in the binary tree. In the worst case, we might have to visit all nodes in the tree.
// Space Complexity: O(h), where h is the height of the binary tree. This space is used by the recursion stack during the depth-first search (DFS) traversal of the tree.

// Approach: We can use a recursive approach to find the lowest common ancestor. The idea is to traverse the tree starting from the root node. If we find either of the two nodes (p or q), we return that node. If we reach a null node, we return null. After traversing both left and right subtrees, if we get non-null values from both sides, it means that one node is found in the left subtree and the other is found in the right subtree, so the current root is their lowest common ancestor. If only one side returns a non-null value, we propagate that value up the recursion stack.

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
    // Why we use the TreeNode* return type? Because we want to return the pointer to the lowest common ancestor node.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        //What is the base case? If the root is null, or if the root is equal to p or q, we return the root.
        if(root == nullptr || root == p || root == q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // What is the result? If the left subtree doesn't contain either p or q, we return the result from the right subtree. If the right subtree doesn't contain either p or q, we return the result from the left subtree. If both subtrees contain p and q, we return the root.
        if(left == nullptr){
            return right;
        }
        else if(right == nullptr){
            return left;
        }
        else{ //if both left and right are not null, it means p and q are found in different subtrees
            return root;
        }
    }
};