// Leetcode 145. Binary Tree Postorder Traversal
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(h), where h is the height of the binary tree (due to recursion stack)

// Approach: The post-order traversal of a binary tree visits the nodes in the following order:
// 1. Traverse the left subtree
// 2. Traverse the right subtree
// 3. Visit the root node

#include <vector>
using namespace std;

  // Definition for a binary tree node.
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
    void postOrder(TreeNode* root, vector<int>& result){
        if(root == nullptr){
            return;
        }

        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postOrder(root, result);
        return result;
    }
};