// Leetcode 102. Binary Tree Level Order Traversal
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(n), where n is the number of nodes in the binary tree (due to the queue used for level order traversal)

// Approach: The level-order traversal of a binary tree visits the nodes level by level from left to right. We can use a queue to facilitate this traversal. The algorithm works as follows:
// 1. Initialize an empty queue and push the root node into it.
// 2. While the queue is not empty, repeat the following steps:
//    a. Get the number of nodes at the current level (size of the queue).
//    b. Initialize an empty vector to store the values of nodes at the current level.
//    c. For each node at the current level, pop it from the queue, add its value to the level vector, and push its left and right children (if they exist) into the queue.
// 3. After processing all nodes at the current level, add the level vector to the result vector.
// 4. Repeat steps 2-3 until all levels have been processed.

#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};