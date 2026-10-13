// Leetcode 257. Binary Tree Paths
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(h), where h is the height of the binary tree (for the recursion stack)

// Approach:
// 1. We will perform a depth-first search (DFS) traversal of the binary tree
// 2. We will maintain a vector to store the path from the root to the current node
// 3. If we reach a leaf node, we will convert the path to a string and add it to the result vector
// 4. If we reach a leaf node, we will backtrack and remove the current node from the path

#include <iostream>
#include <vector>
#include <string>
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
    void getPath(TreeNode* root, vector<int>& path, vector<string>& result) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            string currentPath = "";

            for (int i = 0; i < path.size(); i++) {
                if (i > 0) {
                    currentPath += "->";
                }
                currentPath += to_string(path[i]);
            }

            result.push_back(currentPath);
        } else {
            getPath(root->left, path, result);
            getPath(root->right, path, result);
        }

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;

        getPath(root, path, result);

        return result;
    }
};