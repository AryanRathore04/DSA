// Problem: Minimum time taken to burn binary tree
// Time Complexity: O(N) where N is the number of nodes in the binary tree
// Space Complexity: O(N) for storing parent pointers and visited nodes

// Approach:
// 1. Use a BFS approach to traverse the tree and mark the parent of each node
// 2. Start BFS from the target node and explore its children and parent nodes
// 3. Keep track of the current level and stop when we reach distance k
// 4. The maximum distance from the target node to any other node will be the time taken to burn the binary tree
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
    // Function to find the maximum distance from the target node to any other node in the tree
    int findMaxDistance(map<TreeNode*, TreeNode*> &parent, TreeNode* target){
        queue<TreeNode*> q; // Queue for BFS
        q.push(target); // Start BFS from the target node
        map<TreeNode*, int> vis; // Map to keep track of visited nodes
        vis[target] = 1; // Mark the target node as visited
        int maxi = 0; // Variable to keep track of the maximum distance

        while(!q.empty()){ // Continue BFS until the queue is empty
            int size = q.size(); // Get the number of nodes at the current level
            int fl = 0; // Flag to check if any new nodes are added to the queue at this level
            for(int i=0; i<size; i++){ // Process all nodes at the current level
                TreeNode* node = q.front(); // Get the front node from the queue
                q.pop(); // Remove the front node from the queue
                if(node->left && !vis[node->left]){ // If the current node has a left child and it hasn't been visited yet
                    fl = 1; // Set the flag to indicate that a new node is added
                    vis[node->left] = 1; // Mark the left child as visited
                    q.push(node->left); // Add the left child to the queue for further processing
                }
                if(node->right && !vis[node->right]){ // If the current node has a right child and it hasn't been visited yet
                    fl = 1; // Set the flag to indicate that a new node is added
                    vis[node->right] = 1; // Mark the right child as visited
                    q.push(node->right); // Add the right child to the queue for further processing
                }
                if(parent[node] && !vis[parent[node]]){ // If the current node has a parent and it hasn't been visited yet
                    fl = 1; // Set the flag to indicate that a new node is added
                    vis[parent[node]] = 1; // Mark the parent node as visited
                    q.push(parent[node]); // Add the parent node to the queue for further processing
                }
            }
            if(fl) maxi++; // If any new nodes were added at this level, increment the maximum distance
        }
        return maxi; // Return the maximum distance from the target node to any other node in the tree
    }


    // Function to perform BFS and map each node to its parent, also returns the target node
    TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*> &parent, int start){
        queue<TreeNode*> q; // Queue for BFS
        q.push(root); // Start BFS from the root node
        TreeNode* res; // Variable to store the target node
        while(!q.empty()){ // Continue BFS until the queue is empty
            TreeNode* node = q.front(); // Get the front node from the queue
            if(node->val == start) res = node; // If the current node is the target, store it in res
            q.pop(); // Remove the front node from the queue
            if(node->left){ // If the current node has a left child
                parent[node->left] = node; // Map the left child to its parent (current node)
                q.push(node->left); // Add the left child to the queue for further processing
            }
            if(node->right){ // If the current node has a right child
                parent[node->right] = node; // Map the right child to its parent (current node)
                q.push(node->right); // Add the right child to the queue for further processing
            }
        }
        return res; // Return the target node after BFS is complete
    }


    // Main function to calculate the time taken to burn the binary tree starting from the target node
    int timeToBurnTree(TreeNode* root, int start){
        map<TreeNode*, TreeNode*> parent; // Map to store parent pointers

        TreeNode* target = bfsToMapParents(root, parent, start); // Find the target node and map parents
        int maxi = findMaxDistance(parent,target); // Find the maximum distance from the target node to any other node
        return maxi;
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
    root->right->right = new TreeNode(7);

    Solution sol;
    int start = 5; // Starting node value
    int timeTaken = sol.timeToBurnTree(root, start);
    cout << "Time taken to burn the binary tree starting from node " << start << ": " << timeTaken << endl;

    return 0;
}