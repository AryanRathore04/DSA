// Problem: Count total nodes in a complete binary tree
// Time Complexity: O(log(n)^2) 
// Space Complexity: O(log(n)) due to recursion stack

// Approach:
// 1. Calculate the height of the leftmost path (lh) and the rightmost path (rh) of the tree.
// 2. If lh == rh, then the tree is a perfect binary tree, and the number of nodes can be calculated using the formula 2^h - 1.
// 3. If lh != rh, then recursively count the nodes in the left and right subtrees and add 1 for the root node.
// 4. The recursion continues until the base case is reached (when the node is nullptr).

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    int countNode(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if(lh == rh){
            return (1 << lh) - 1; // 2^h - 1
        }

        return 1 + countNode(root->left) + countNode(root->right);
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

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    int totalNodes = sol.countNode(root);
    cout << "Total nodes in the complete binary tree: " << totalNodes << endl;
    // Answer should be 6 for this tree.

    // Clean up memory (not shown for brevity)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}