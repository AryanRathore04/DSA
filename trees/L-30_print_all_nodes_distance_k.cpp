// Problem: Print all nodes at distance k from a given node in a binary tree
// Time Complexity: O(n) where n is the number of nodes in the binary tree
// Space Complexity: O(n) for storing parent pointers and visited nodes

// Approach:
// 1. Use a BFS approach to traverse the tree and mark the parent of each node
// 2. Start BFS from the target node and explore its children and parent nodes
// 3. Keep track of the current level and stop when we reach distance k
// 4. Collect all nodes at distance k and return them
// Note: The tree is assumed to be a binary tree and the target node is guaranteed to be present in the tree.


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    // Helper function to mark parents of all nodes in the tree
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
        queue<TreeNode*> queue; // Initialize a queue for BFS
        queue.push(root); // Start BFS from the root node
        while(!queue.empty()){
            TreeNode* current = queue.front(); // Get the front node from the queue
            queue.pop(); // Remove the front node from the queue
            if(current->left){ // If the left child exists
                parent_track[current->left] = current; // Mark the parent of the left child
                queue.push(current->left); // Add the left child to the queue
            }
            if(current->right){ // If the right child exists
                parent_track[current->right] = current; // Mark the parent of the right child
                queue.push(current->right); // Add the right child to the queue
            }
        }
    }

    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // To keep track of parent nodes
        markParents(root, parent_track, target); // Mark parents of all nodes in the tree

        unordered_map<TreeNode*, bool> visited; // To keep track of visited nodes
        queue<TreeNode*> queue; // Initialize a queue for BFS
        queue.push(target); // Start BFS from the target node
        visited[target] = true; // Mark the target node as visited
        int curr_level = 0; // Initialize the current level to 0

        // Perform BFS to find all nodes at distance k from the target node
        while(!queue.empty()){
            int size = queue.size(); // Get the number of nodes at the current level
            if(curr_level++ == k) break; // If the current level is equal to k, break the loop
            for(int i = 0; i < size; i++){
                TreeNode* current = queue.front(); // Get the front node from the queue
                queue.pop(); // Remove the front node from the queue

                if(current->left && !visited[current->left]){ // If the left child exists and is not visited
                    queue.push(current->left); // Add the left child to the queue
                    visited[current->left] = true; // Mark the left child as visited
                }
                if(current->right && !visited[current->right]){ // If the right child exists and is not visited
                    queue.push(current->right); // Add the right child to the queue
                    visited[current->right] = true; // Mark the right child as visited
                }
                if(parent_track[current] && !visited[parent_track[current]]){ // If the parent exists and is not visited
                    queue.push(parent_track[current]); // Add the parent to the queue
                    visited[parent_track[current]] = true; // Mark the parent as visited
                }
            }
        }

        vector<int> result; // To store the result nodes at distance k
        while(!queue.empty()){ // Collect all nodes at distance k
            TreeNode* current = queue.front(); // Get the front node from the queue
            queue.pop(); // Remove the front node from the queue
            result.push_back(current->data); // Add the node's data to the result
        }
        return result;
    }
};


int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;
    int k = 2;
    vector<int> result = solution.distanceK(root, root->left, k); // Find nodes at distance k from node with value 5

    cout << "Nodes at distance " << k << " from target node: ";
    for(int val : result) {
        cout << val << " "; // Print the result
    }
    cout << endl;

    // Clean up memory (delete the tree nodes)
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root;

    return 0;
}