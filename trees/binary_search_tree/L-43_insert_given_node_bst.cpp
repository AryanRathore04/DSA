// Problem: Insert into a Binary Search Tree
// Given the root node of a binary search tree (BST) and a value to insert into the tree, return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

// Time Complexity: O(h), where h is the height of the tree. In the average case, the height of a balanced BST is log(n), where n is the number of nodes in the tree. In the worst case, the height can be n (for a skewed tree).
// Space Complexity: O(1) for the iterative approach, as we are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the input tree.


// Approach:
// 1. If the root is NULL, create a new node with the given value and return it as the new root.
// 2. Initialize a pointer to traverse the tree starting from the root.
// 3. While traversing the tree:
//    - If the current node's value is less than or equal to the value to insert, move to the right subtree. If the right child is NULL, insert the new value as the right child and break the loop.
//    - If the current node's value is greater than the value to insert, move to the left subtree. If the left child is NULL, insert the new value as the left child and break the loop.
// 4. Return the original root of the tree after the insertion is complete.

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
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root == NULL) return new TreeNode(val);
        TreeNode* curr = root;
        
        while(true){
            if(curr->val <= val){
                if(curr->right != NULL){
                    curr = curr->right;
                } else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left != NULL){
                    curr = curr->left;
                } else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};


int main() {
    Solution sol;
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int valToInsert = 5;
    root = sol.insertIntoBST(root, valToInsert);

    // Function to print the BST in-order to verify insertion
    function<void(TreeNode*)> inOrderPrint = [&](TreeNode* node) {
        if (node == NULL) return;
        inOrderPrint(node->left);
        cout << node->val << " ";
        inOrderPrint(node->right);
    };

    cout << "In-order traversal of BST after insertion: ";
    inOrderPrint(root);
    cout << endl;

    return 0;
}