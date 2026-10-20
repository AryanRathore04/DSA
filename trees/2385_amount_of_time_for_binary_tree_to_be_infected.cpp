// Leetcode 2385. Amount of Time for Binary Tree to Be Infected
// Time Complexity: O(N) where N is the number of nodes in the binary tree. We visit each node once during the BFS traversal to map parents and once during the BFS traversal to find the maximum distance.
// Space Complexity: O(N) for storing parent pointers and visited nodes. We use a map to store the parent of each node and a map to keep track of visited nodes during the BFS traversal

// Approach:
// 1. Use a BFS approach to traverse the tree and mark the parent of each node
// 2. Start BFS from the target node and explore its children and parent nodes
// 3. Keep track of the current level and stop when we reach distance k
// 4. The maximum distance from the target node to any other node will be the time taken to infect the entire binary tree
// Note: The tree is assumed to be a binary tree and the target node is guaranteed to be present in the tree.


#include <iostream>
#include <vector>
#include <map>
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
    int findMaxDistance(map<TreeNode*, TreeNode*> &parent, TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int> vis;
        vis[target] = 1;
        int time = 0;

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    flag = true;
                    vis[node->left] = 1;
                    q.push(node->left);
                }

                if(node->right && !vis[node->right]){
                    flag = true;
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if(parent[node] && !vis[parent[node]]){
                    flag = true;
                    vis[parent[node]] = 1;
                    q.push(parent[node]);
                }
            }

            if(flag) time++;
        }

        return time;
    }

    TreeNode* bfsToMapParent(TreeNode* root, map<TreeNode*, TreeNode*> &parent, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target;

        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val == start) target = node;
            q.pop();

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return target;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent;

        TreeNode* target = bfsToMapParent(root, parent, start);
        int time = findMaxDistance(parent, target);

        return time;
    }
};