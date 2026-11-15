// Problem: Find Ceil in Binary Search Tree
// Given a Binary Search Tree (BST) and a key, find the ceil value of the key in the BST. The ceil value of a key is the smallest value in the BST that is greater than or equal to the key. If no such value exists, return -1.

// Time Complexity: O(h), where h is the height of the tree. In the average case, the height of a balanced BST is log(n), where n is the number of nodes in the tree. In the worst case, the height can be n (for a skewed tree).
// Space Complexity: O(1) for the iterative approach, as we are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the input tree.

// Approach:
// 1. Start from the root of the BST.
// 2. Initialize a variable to store the ceil value, initially set to -1.
// 3. Traverse the tree:
//    - If the current node's value is equal to the key, return the current node's value as the ceil.
//    - If the current node's value is less than the key, move to the right subtree (as all values in the left subtree will be smaller).
//    - If the current node's value is greater than the key, update the ceil value to the current node's value and move to the left subtree (as there might be a smaller value that is still greater than or equal to the key).
// 4. Repeat the process until you reach a null node. If the ceil value was updated during the traversal, return it; otherwise, return -1 to indicate that no ceil value exists in the BST for the given key.

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
    int findCeil(TreeNode* root, int key){
        int ceil = -1;
        while(root){
            if(root->val == key){
                ceil = root->val;
                return ceil;
            }

            if(key >root->val){
                root = root->right;
            }
            else{
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
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

    int key = 5;
    int ceilValue = sol.findCeil(root, key);
    if (ceilValue != -1) {
        cout << "Ceil of " << key << " is: " << ceilValue << endl;
    } else {
        cout << "Ceil of " << key << " does not exist." << endl;
    }

    return 0;
}