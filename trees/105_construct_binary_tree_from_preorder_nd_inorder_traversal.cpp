// Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Time Complexity: O(n), where n is the number of nodes in the tree. We visit each node once to construct the tree.
// Space Complexity: O(n), for storing the inorder map and the recursive call stack.

// Approach:
// 1. Create a map to store the index of each value in the inorder array for quick lookup.
// 2. Use a recursive function to build the tree. The first element of the preorder array is the root of the tree. Find this root in the inorder array to determine the left and right subtrees.
// 3. Recursively build the left and right subtrees using the corresponding elements in the preorder and inorder arrays.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // This function builds a binary tree from preorder and inorder traversal arrays.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        map<int, int> inorderMap; // This map will store the index of each value in the inorder array for quick lookup.

        // Populate the map with the indices of the inorder array.
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        // Call the recursive function to build the tree and return the root.
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
        return root;
    }

    // This function recursively builds a binary tree from preorder and inorder traversal arrays.
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inorderMap){

        // Base case: if the current subarray is invalid, return NULL.
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }

        // The first element in the current preorder subarray is the root of the current subtree.
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inorderMap[root->val]; // Find the index of the root in the inorder array using the map for O(1) lookup.


        int numsLeft = inRoot - inStart; // Calculate the number of nodes in the left subtree.

        // Recursively build the left subtree using the corresponding elements in the preorder and inorder arrays.
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inorderMap);

        // Recursively build the right subtree using the remaining elements in the preorder and inorder arrays.
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }
};