// LeetCode 106: Construct Binary Tree from Inorder and Postorder Traversal
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Time Complexity: O(n), where n is the number of nodes in the tree. We visit each node once to construct the tree.
// Space Complexity: O(n), for storing the inorder map and the recursive call stack.

// Approach:
// 1. Create a map to store the index of each value in the inorder array for quick lookup.
// 2. Use a recursive function to build the tree. The last element of the postorder array is the root of the tree. Find this root in the inorder array to determine the left and right subtrees.
// 3. Recursively build the left and right subtrees using the corresponding elements in the inorder and postorder arrays.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;

       unordered_map<int, int> inorderMap;

        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
    }


private:
    TreeNode* buildTreePostIn(vector<int>& inorder, int inStart, int inEnd, vector<int>&postorder, int postStart, int postEnd, unordered_map<int, int>& inorderMap){
        if(inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inorderMap[postorder[postEnd]];

        int numsLeft = inRoot - inStart;

        root->left = buildTreePostIn(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inorderMap);

        root->right = buildTreePostIn(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inorderMap); 


        return root;
    }
};