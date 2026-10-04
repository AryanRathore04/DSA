// Problem: Vertical Order Traversal of a Binary Tree
// Time Complexity: O(N log N), where N is the number of nodes in the binary tree. We visit each node once, and for each node, we may need to insert its value into a multiset, which takes O(log N) time.
// Space Complexity: O(N), where N is the number of nodes in the binary tree.

// Approach: We can perform a breadth-first search (BFS) traversal of the binary tree while keeping track of the horizontal distance (x-coordinate) and vertical distance (y-coordinate) of each node. We can use a map to store the nodes at each horizontal distance, where the key is the x-coordinate and the value is another map that stores the nodes at each vertical distance (y-coordinate). The inner map will have a multiset to store the node values, which allows us to automatically sort the values in ascending order. After traversing the tree, we can iterate through the map and construct the final result.

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if(node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                for(int val : q.second){
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    // Print the result
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}