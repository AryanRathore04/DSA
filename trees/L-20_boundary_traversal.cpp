// Problem: Boundary Traversal of a Binary Tree
// Given a binary tree, return the boundary traversal of the tree in anti-clockwise direction starting from the root. The boundary includes the left boundary, leaves, and right boundary in order without duplicate nodes.

// Time Complexity: O(n), where n is the number of nodes in the binary tree. We visit each node once.
// Space Complexity: O(n), for storing the result and the temporary vectors used for left and right boundaries.

// Approach:
// 1. Check if the root is null. If it is, return an empty vector.
// 2. If the root is not a leaf, add its value to the result vector.
// 3. Add the left boundary nodes (excluding the root and leaves) to the result vector.
// 4. Add all the leaf nodes to the result vector.
// 5. Add the right boundary nodes (excluding the root and leaves) to the result vector in reverse order.
// 6. Return the result vector containing the boundary traversal of the binary tree.

#include <iostream>
#include <stack>
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

    // Add the left boundary nodes (excluding the root and leaves) to the result vector
    void addLeftBoundary(TreeNode * root, vector<int> &res){
        if(!root || isLeaf(root)) return; // If root is null or a leaf, return
        TreeNode* curr = root->left; // Start from the left child of the root
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->val); // Add non-leaf nodes to temp
            if(curr->left) curr = curr->left; // Move to the left child if it exists
            else curr = curr->right; // Otherwise, move to the right child
        }
        for(int i = temp.size() - 1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }

    void addRightBoundary(TreeNode * root, vector<int> &res){
        TreeNode* curr = root->right; // Start from the right child of the root
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->val); // Add non-leaf nodes to temp
            if(curr->right) curr = curr->right; // Move to the right child if it exists
            else curr = curr->left; // Otherwise, move to the left child
        }
        for(int i = temp.size() - 1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }

    // Add all leaf nodes to the result vector
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
        if(!isLeaf(root)) res.push_back(root->val); // Add root value if it's not a leaf node
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<int> boundary = sol.printBoundary(root);

    cout << "Boundary Traversal: ";
    for(int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (not shown)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    return 0;
}