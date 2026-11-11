// Leetcode 114. Flatten Binary Tree to Linked List
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(1), since we are modifying the tree in place and not using any additional data structures.


// Approach:
// 1. Start with the root node of the binary tree.
// 2. While the current node is not null, do the following:
//    a. If the current node has a left child, find the rightmost node of the left subtree (predecessor).
//    b. Connect the right child of the current node to the right child of the predecessor.
//    c. Move the left subtree to the right and set the left child of the current node to null.
//    d. Move to the right child of the current node and repeat the process.
// 3. Continue this process until all nodes are processed, resulting in a flattened linked list representation of the binary tree.
// 4. Finally, the right pointers of the nodes will point to the next node in the flattened list, and the left pointers will be null.


#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode* current = root;

        while(current != NULL){

            if(current->left != NULL){
                TreeNode* predecessor = current->left;
                while(predecessor->right){
                    predecessor = predecessor->right;
                }

                predecessor->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }

            current = current->right;
        }
    }
};