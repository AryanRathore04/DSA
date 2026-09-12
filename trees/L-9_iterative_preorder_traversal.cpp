// Problem: Preorder Traversal of a Binary Tree (Iterative Approach)
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(n), where n is the number of nodes in the binary tree (due to the stack used for iterative traversal)

// Approach: The preorder traversal of a binary tree visits the nodes in the order: root, left subtree, right subtree. We can use a stack to facilitate this traversal. The algorithm works as follows:
// 1. Initialize an empty stack and push the root node into it.
// 2. While the stack is not empty, repeat the following steps:
//    a. Pop the top node from the stack and add its value to the result vector
//    b. Push the right child of the popped node (if it exists) into the stack.
//    c. Push the left child of the popped node (if it exists) into the stack.
// 3. Repeat steps 2a-2c until the stack is empty.

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> preorder;
        if(root == nullptr){
            return preorder;
        }

        stack<TreeNode*> st; // stack to store the nodes
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right != nullptr) st.push(root->right);
            if(root->left != nullptr) st.push(root->left);
        }
        return preorder;
    }
};

int main() {
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    Solution solution;
    vector<int> result = solution.preorderTraversal(root);

    // Print the result
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}