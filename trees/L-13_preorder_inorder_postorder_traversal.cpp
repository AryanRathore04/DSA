// Problem: Given a binary tree, return the preorder, inorder and postorder traversals of its nodes' values in a single traversal.

// Time Complexity: O(n) where n is the number of nodes in the binary tree.
// Space Complexity: O(n) where n is the number of nodes in the binary tree.

// Approach: 1. Use a stack to perform an iterative traversal of the binary tree.
// 2. Use a pair to keep track of the current node and its state (1 for preorder, 2 for inorder, 3 for postorder).
// 3. For each node, based on its state, add its value to the corresponding traversal vector and update its state.
// 4. Push the left and right children of the node onto the stack as needed.
// 5. Finally, combine the three traversal vectors into a single result vector and return it.

#include <iostream>
#include <vector>
#include <stack>
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

    vector<int> preInPostTraversal(TreeNode* root){
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        vector<int> pre, in, post;

        if(root == nullptr){
            return {};
        }

        while (!st.empty()){
            auto it = st.top();
            st.pop();

            // this is part of pre
            // increment 1 to 2
            // push the left side of the tree
            if(it.second == 1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);

                if(it.first->left != nullptr){
                    st.push({it.first->left, 1});
                }
            }

            // this is part of in
            // increment 2 to 3
            // push the right side of the tree
            else if(it.second == 2){
                in.push_back(it.first->val);
                it.second++;
                st.push(it);

                if(it.first->right != nullptr){
                    st.push({it.first->right, 1});
                }
            }

            // this is part of post
            // increment 3 to 4
            else{
                post.push_back(it.first->val);
            }
        }

        vector<int> ans;
        ans.insert(ans.end(), pre.begin(), pre.end());
        ans.insert(ans.end(), in.begin(), in.end());
        ans.insert(ans.end(), post.begin(), post.end());

        return ans;
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

    Solution sol;
    vector<int> result = sol.preInPostTraversal(root);

    int n = result.size() / 3;

cout << "Preorder: ";
for(int i = 0; i < n; i++){
    cout << result[i] << " ";
}

cout << "\nInorder: ";
for(int i = n; i < 2*n; i++){
    cout << result[i] << " ";
}

cout << "\nPostorder: ";
for(int i = 2*n; i < 3*n; i++){
    cout << result[i] << " ";
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
