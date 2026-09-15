// Problem: Write a C++ program to perform iterative postorder traversal of a binary tree using one stack.

// Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited once.
// Space Complexity: O(n), where n is the number of nodes in the binary tree. In the worst case, the stack can hold all the nodes in the tree.

// Approach: 1. Initialize the result vector and a stack.
// 2. While the current node is not null or the stack is not empty, do the following:
//    a. If the current node is not null, push it onto the stack and move to its left child.
//    b. If the current node is null, peek the node from the stack and check its right child. If the right child is null or has already been visited, pop the node from the stack, add its value to the result vector, and mark it as visited. Otherwise, move to the right child of the node.
// 3. Return the result vector containing the postorder traversal of the tree.

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> st;

        while(root != nullptr || !st.empty()){
            if(root != nullptr){
                st.push(root);
                root = root->left;
            } else {
                TreeNode* temp = st.top()->right;
                if(temp == nullptr){
                    temp = st.top();
                    st.pop();
                    result.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        result.push_back(temp->val);
                    }
                } else {
                    root = temp;
                }
            }
        }
        return result;
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
    vector<int> result = solution.postorderTraversal(root);
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}