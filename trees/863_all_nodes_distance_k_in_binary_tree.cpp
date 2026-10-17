// Leetcode 863: All Nodes Distance K in Binary Tree
// Time Complexity: O(N) where N is the number of nodes in the binary tree
// Space Complexity: O(N) for storing parent pointers and visited nodes

// Approach:
// 1. Use a BFS approach to traverse the tree and mark the parent of each node
// 2. Start BFS from the target node and explore its children and parent nodes
// 3. Keep track of the current level and stop when we reach distance k
// 4. Collect all nodes at distance k and return them
// Note: The tree is assumed to be a binary tree and the target node is guaranteed to be present in the tree.

#include <iostream>
#include <vector>
#include <unordered_map>
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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            TreeNode* current = queue.front();
            queue.pop();

            if(current->left){
                parent_track[current->left] = current;
                queue.push(current->left);
            }

            if(current->right){
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track, target);

        unordered_map<TreeNode*, bool> visit;

        queue<TreeNode*> queue;
        queue.push(target);
        visit[target] = true;
        int curr_level = 0;

        while(!queue.empty()){
            int size = queue.size();

            if(curr_level++ == k) break;

            for(int i = 0; i < size; i++){
                TreeNode* current = queue.front();
                queue.pop();

                if(current->left && !visit[current->left]){
                    queue.push(current->left);
                    visit[current->left] = true;
                }

                if(current->right && !visit[current->right]){
                    queue.push(current->right);
                    visit[current->right] = true;
                }

                if(parent_track[current] && !visit[parent_track[current]]){
                    queue.push(parent_track[current]);
                    visit[parent_track[current]] = true;
                }
            }
        }

        vector<int> result;

        while(!queue.empty()){
            TreeNode* current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }

        return result;
    }
};