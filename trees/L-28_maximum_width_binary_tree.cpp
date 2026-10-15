// Problem: Maximum Width of Binary Tree
// Given a binary tree, write a function to get the maximum width of the given tree.

// Time Complexity: O(n), where n is the number of nodes in the binary tree. We visit each node once.
// Space Complexity: O(n), where n is the number of nodes in the binary tree. In the worst case, we may have to store all nodes at the last level in the queue.

// Approach:
// 1. We will perform a level order traversal of the binary tree using a queue.
// 2. For each level, we will keep track of the indices of the nodes. The index of the left child is 2 * index + 1 and the index of the right child is 2 * index + 2.
// 3. For each level, we will calculate the width as the difference between the last and first indices plus one.
// 4. We will keep track of the maximum width found across all levels and return it at the end.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    int widthOfBinaryTree(TreeNode* root){
        if(!root) return 0;
        int ans = 0;
        // Use a queue to perform level order traversal
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while ((!q.empty())){
            // Get the size of the current level
            int size = q.size();
            // Get the minimum index of the current level to avoid integer overflow
            int mmin = q.front().second;
            // Initialize first and last indices for the current level
            int first, last;

            // Iterate through all nodes in the current level
            for(int i = 0; i < size; i++){
                // Get the current node and its index, adjusted by the minimum index
                int cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = cur_id; // Store the first index of the current level
                if(i == size - 1) last = cur_id; // Store the last index of the current level

                // Add the left and right children to the queue with their respective indices
                if(node->left){
                    q.push({node->left, cur_id * 2 + 1});
                }
                if(node->right){
                    q.push({node->right, cur_id * 2 + 2});
                }
            }
            // Update the maximum width found so far
            ans = max(ans, last - first + 1);
        }

        return ans;
        
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    int width = sol.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << width << endl;

    // Clean up memory (not shown for brevity)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}