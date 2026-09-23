// Problem: Maximum Depth of Binary Tree
// Time Complexity: O(n), where n is the number of nodes in the binary tree. We visit each node once.
// Space Complexity: O(h), where h is the height of the binary tree. This space is used by the recursion stack. In the worst case, the height of the tree can be n for a skewed tree, leading to O(n) space complexity. In the best case of a balanced tree, the height is log(n), leading to O(log(n)) space complexity.

// Approach: We can solve this problem using a recursive depth-first search (DFS) approach. The idea is to traverse the tree and calculate the depth of each subtree. The maximum depth of the tree will be the maximum depth of its left and right subtrees plus one for the current node.

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
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

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

    Solution solution;
    int depth = solution.maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;

    // Clean up memory (not shown for brevity)
    delete root->right->left->left;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root;
    return 0;
}