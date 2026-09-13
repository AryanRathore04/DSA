// Problem: Given the root of a binary tree, return the postorder traversal of its nodes' values.
// Time Complexity: O(n), where n is the number of nodes in the tree. Each node is visited once.
// Space Complexity: O(n), where n is the number of nodes in the tree. In the worst case, the stack can hold all the nodes in the tree.

// Approach: 1. Initialize the result vector and two stacks, st1 and st2.
// 2. Push the root node onto st1.
// 3. While st1 is not empty, do the following:
//    a. Pop the top node from st1 and push it onto st2.
//    b. If the popped node has a left child, push it onto st1.
//    c. If the popped node has a right child, push it onto st1.
// 4. After the loop, pop all nodes from st2 and add their values to the result vector.
// 5. Return the result vector containing the postorder traversal of the tree.

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
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);

            if(root->left != nullptr){
                st1.push(root->left);
            }

            if(root->right != nullptr){
                st1.push(root->right);
            }
        }

        while (!st2.empty()){
            result.push_back(st2.top()->val);
            st2.pop();
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

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

   // Clean up the allocated memory
    delete root->left->right->left; // Node 6
    delete root->left->right;        // Node 5
    delete root->left->left;         // Node 4
    delete root->left;                // Node 2
    delete root->right->right->left; // Node 9
    delete root->right->right->right; // Node 10
    delete root->right->right;       // Node 8
    delete root->right->left;        // Node 7
    delete root->right;               // Node 3
    delete root;                      // Node 1

    return 0;
}