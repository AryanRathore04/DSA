// Problem: Implement Morris Traversal for Inorder Traversal of a Binary Tree
// Solution: The Morris Traversal algorithm allows us to perform an inorder traversal of a binary tree without using recursion or a stack. It modifies the tree structure temporarily to create links back to the parent nodes, enabling us to traverse the tree in O(n) time and O(1) space complexity.

// The algorithm works as follows:
// 1. Initialize the current node as the root.
// 2. While the current node is not NULL:
//    a. If the current node has no left child, visit the current node and move to its right child.
//    b. If the current node has a left child, find the inorder predecessor of the current node (the rightmost node in the left subtree).
//       i. If the right child of the predecessor is NULL, set it to point to the current node and move the current node to its left child.
//       ii. If the right child of the predecessor is the current node, it means we have finished visiting the left subtree. We remove the temporary link, visit the current node, and move to its right child.
// 3. Repeat the process until all nodes are visited.


#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * Performs an inorder traversal of a binary tree using Morris Traversal.
     * @param root The root of the binary tree.
     * @return A vector containing the values of the nodes in inorder.
     */
    vector<int> getInorder(TreeNode* root){
        vector<int> result;
        TreeNode* current = root;

        while(current != NULL){
            if(current->left == NULL){
                result.push_back(current->val);
                current = current->right;
            }
            else{
                TreeNode *prev = current->left; // Find the inorder predecessor of current and predecessor means the rightmost node in the left subtree of current

                // To find the predecessor, we keep going to the right until we reach a node that doesn't have a right child or its right child is current
                while(prev->right && prev->right != current){
                    prev = prev->right; // Move to the right child of the predecessor
                }

                // If the right child of the predecessor is NULL, we set it to current and move current to its left child. This creates a temporary link back to current, allowing us to return to it after finishing the left subtree.
                if(prev->right == NULL){
                    prev->right = current;
                    current = current->left;
                }
                else{
                    // If the right child of the predecessor is current, we remove the temporary link and visit the current node.
                    prev->right = NULL;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return result;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> inorderTraversal = solution.getInorder(root);

    cout << "Inorder Traversal: ";
    for(int val : inorderTraversal) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (not shown)
    delete root->right->left;
    delete root->right;
    delete root;
    return 0;
}