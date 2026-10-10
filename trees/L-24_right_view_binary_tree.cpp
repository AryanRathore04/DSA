// Problem: Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// Time Complexity: O(n), where n is the number of nodes in the binary tree. We visit each node once.
// Space Complexity: O(h), where h is the height of the binary tree. In the worst case, the recursion stack can go as deep as the height of the tree.

// Approach: We can use a depth-first search (DFS) approach to traverse the binary tree. We will keep track of the current level of the tree and store the first node we encounter at each level in a result vector. Since we want the right side view, we will first visit the right child before the left child.

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
    vector<int> rightSideView(TreeNode* root){
        vector<int> result;
        recursion(root, 0, result);
        return result;
    }

    private:
    void recursion(TreeNode* root, int level, vector<int>& result){
        if(root == nullptr) return ;
        if(result.size() == level) result.push_back(root->val);
        recursion(root->right, level + 1, result);
        recursion(root->left, level + 1, result);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<int> rightView = solution.rightSideView(root);

    cout << "Right side view of the binary tree: ";
    for (int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}