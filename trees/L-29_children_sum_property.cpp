// Problem: Given a binary tree, write a function to change the value of each node to be equal to the sum of its children. If a node has no children, its value remains unchanged. If a node has only one child, its value should be updated to the value of that child.

// Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited once during the traversal.
// Space Complexity: O(h), where h is the height of the binary tree. This space is used by the recursion stack during the traversal.

// Approach: The function uses a recursive approach to traverse the binary tree. For each node, it calculates the sum of its children and updates the node's value accordingly. If the node has no children, its value remains unchanged. If it has only one child, its value is updated to that child's value. The function continues this process for all nodes in the tree.

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
    public:
    void changeTree(TreeNode* root){
        if(root == nullptr) return;
        int childSum = 0; // Initialize childSum to 0

        // Calculate the sum of the left and right child nodes
        if(root->left) {
            childSum += root->left->data;
        }
        if(root->right) {
            childSum += root->right->data;
        }

        // Update the current node's data if the sum of its children is greater than its own data
        if(childSum >= root->data){
            root->data = childSum;
        }
        // If the current node's data is greater than the sum of its children, propagate the current node's data to its children
        else {
            if(root->left) {
                root->left->data = root->data; // Easy Language: Update the left child's data to the current node's data
            }
            if(root->right) {
                root->right->data = root->data;
            }
        }

        changeTree(root->left);
        changeTree(root->right);

        int total = 0; // Initialize total to 0
        // Calculate the sum of the left and right child nodes again after the recursive calls
        if(root->left) {
            total += root->left->data;
        }
        if(root->right) {
            total += root->right->data;
        }
        // Update the current node's data to the sum of its children
        // This is done after the recursive calls to ensure the children's values are updated first
        if(root->left or root->right) {
            root->data = total;
        }
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode{50, nullptr, nullptr};
    root->left = new TreeNode{7, nullptr, nullptr};
    root->right = new TreeNode{2, nullptr, nullptr};
    root->left->left = new TreeNode{3, nullptr, nullptr};
    root->left->right = new TreeNode{5, nullptr, nullptr};
    root->right->right = new TreeNode{1, nullptr, nullptr};

    Solution sol;
    sol.changeTree(root);

    // Function to print the tree in level order to verify the changes
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }

    // Clean up memory (not shown for brevity)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;
    return 0;
}

