// Problem: Given the root of a binary tree, return the inorder traversal of its nodes' values.
// Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited once.
// Space Complexity: O(h), where h is the height of the binary tree. In the worst case, the stack can hold all the nodes in a single path from the root to a leaf node.

// Approach: We can use an iterative approach to perform the inorder traversal of the binary tree. We will use a stack to keep track of the nodes. We will start from the root node and keep traversing to the left child until we reach a null node. At that point, we will pop the top node from the stack, add its value to the result vector, and then move to its right child. We will repeat this process until we have visited all nodes in the tree.

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
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> result;
        while(true){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            } else {
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                result.push_back(node->val);
                node = node->right;
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
    vector<int> result = solution.inorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}