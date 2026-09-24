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
        if(node == nullptr) return 0;

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(5);
    root->right->left->left->left = new TreeNode(9);
    root->right->right->right = new TreeNode(7);
    root->right->right->right->right = new TreeNode(8);

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    // Clean up memory (delete nodes)
    delete root->right->left->left->left;
    delete root->right->left->left;
    delete root->right->right->right->right;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}