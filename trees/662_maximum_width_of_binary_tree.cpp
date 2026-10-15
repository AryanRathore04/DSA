// Leetcode 662. Maximum Width of Binary Tree
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            int first, last;

            for(int i = 0; i < size; i++){
                int curr_id = q.front().second - mmin;
                
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = curr_id;
                if(i == size - 1) last = curr_id;

                if(node->left){
                    q.push({node->left, (long long)curr_id * 2 + 1});
                }

                if(node->right){
                    q.push({node->right, (long long)curr_id * 2 + 2});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};