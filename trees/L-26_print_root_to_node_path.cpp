// Problem: Print path from root to a given node in a binary tree
// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(h), where h is the height of the binary tree (for the recursion stack)

// Approach:
// 1. We will perform a depth-first search (DFS) traversal of the binary tree
// 2. We will maintain a vector to store the path from the root to the current node
// 3. If we reach the target node, we will return true and the path
// 4. If we reach a leaf node and haven't found the target, we will backtrack and remove the current node from the path


#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
    bool getPath(TreeNode *root, vector<int> &path, int x){

        if(!root) {
            return false;
        }

        path.push_back(root->data);

        if(root->data == x) {
            return true;
        }

        if(getPath(root->left, path, x) || getPath(root->right, path, x)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    public:
    vector<int> solve(TreeNode* A, int B){

        vector<int> path;
        if(A == nullptr) {
            return path;
        }
        getPath(A, path, B);
        return path;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    int target = 5;
    vector<int> path = solution.solve(root, target);

    cout << "Path from root to node " << target << ": ";
    for (int val : path) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}