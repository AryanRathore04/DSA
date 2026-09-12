// Problem: Level Order Traversal of a Binary Tree
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
    public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans; 
        }

        queue<TreeNode*> q; // queue to store the nodes at each level
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level; // vector to store the values of nodes at the current level

            for(int i = 0; i < size; i++){
                TreeNode *node = q.front(); // get the front node of the queue
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

int main() {
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    // Print the level order traversal result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}