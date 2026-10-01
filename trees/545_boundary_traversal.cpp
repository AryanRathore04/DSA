// Leetcode 545. Boundary of Binary Tree
// Time Complexity: O(n) where n is the number of nodes in the binary tree
// Space Complexity: O(n) where n is the number of nodes in the binary tree

// Approach: 
// 1. Check if the root is null, if yes return an empty vector.
// 2. If the root is not a leaf node, add its value to the result
// 3. Traverse the left boundary of the tree and add the values of non-leaf nodes to the result vector.
// 4. Traverse the leaf nodes of the tree and add their values to the result vector.
// 5. Traverse the right boundary of the tree and add the values of non-leaf nodes to the result vector in reverse order.
// 6. Return the result vector containing the boundary values of the binary tree.

#include <iostream>
#include <stack>
#include <vector>
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
    bool isLeaf(TreeNode *node){
        return !node->left && !node->right;
    }

    void addLeftBoundary(TreeNode *root, vector<int> &res){
        TreeNode* curr = root->left;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->val);
            if(curr->left) curr = curr->left;
            else{
                curr = curr->right;
            }
        }

        for(int i = temp.size() - 1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }

    void addRightBoundary(TreeNode * root, vector<int> &res){
        TreeNode* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->val);
            if(curr->right) curr = curr->right;
            else{
                curr = curr->left;
            }
        }

         for(int i = temp.size() - 1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode * root, vector<int> &res){
        if(isLeaf(root)){
            res.push_back(root->val); // Add leaf node value to res
            return;
        }
        if(root->left) addLeaves(root->left, res); // Recur for left subtree
        if(root->right) addLeaves(root->right, res); // Recur for right subtree
    }

    public:
    vector<int> printBoundary(TreeNode *root){
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->val);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};