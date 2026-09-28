// Problem: ZigZag Level Order Traversal of a Binary Tree
// Time complexity: O(n) where n is the number of nodes in the binary tree
// Space complexity: O(n) where n is the number of nodes in the binary tree

// Approach: We can use a queue to perform a level order traversal of the binary tree. We will keep track of the current level and the direction of traversal (left to right or right to left). For each level, we will create a vector to hold the values of the nodes at that level. If the direction is left to right, we will fill the vector from left to right, otherwise we will fill it from right to left. After processing all nodes at the current level, we will add the vector to the result and toggle the direction for the next level.

#include <iostream>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while(!nodesQueue.empty()){
            int size = nodesQueue.size(); // Number of nodes at the current level
            vector<int> row(size); // Create a vector to hold the current level's values

            for(int i = 0; i < size; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                //Find position to dill node's value
                int index = (leftToRight) ? i : (size - 1 - i);

                row[index] = node->val;
                if(node->left){
                    nodesQueue.push(node->left);
                }

                if(node->right){
                    nodesQueue.push(node->right);
                }
            }

            // after this level
            leftToRight = !leftToRight;
            result.push_back(row);
        }

        return result;
    }
};


int main(){
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    for(const auto& level : result){
        for(int val : level){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

