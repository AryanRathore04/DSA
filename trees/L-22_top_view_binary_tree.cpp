// Problem: Top View of Binary Tree
// Time Complexity: O(N log N) where N is the number of nodes in the binary tree. The log N factor comes from the insertion and retrieval operations in the map.
// Space Complexity: O(N) for storing the nodes in the map and the queue.

// Approach:
// 1. We perform a level order traversal of the binary tree using a queue.
// 2. For each node, we keep track of its horizontal distance (line) from the root. The root has a horizontal distance of 0, the left child has a horizontal distance of -1, and the right child has a horizontal distance of +1.
// 3. We use a map to store the first node encountered at each horizontal distance. The key of the map is the horizontal distance, and the value is the node's value.
// 4. After the traversal, we extract the values from the map in order of their keys (horizontal distances) to get the top view of the binary tree.

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<int> topView(TreeNode* root){
            vector<int> ans;
            if(root == nullptr) return ans;
            map<int, int> mpp;
            queue<pair<TreeNode*, int>> q;
            q.push({root, 0});

            while(!q.empty()){
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                int line = it.second;

                if(mpp.find(line) == mpp.end()){
                    mpp[line] = node->val;
                } 

                if(node->left != nullptr){
                    q.push({node->left, line - 1});
                }

                if(node->right != nullptr){
                    q.push({node->right, line +1});
                }
            }

            for(auto it : mpp){
                ans.push_back(it.second);
            }

            return ans;
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

    Solution sol;
    vector<int> result = sol.topView(root);

    cout << "Top view of the binary tree: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}