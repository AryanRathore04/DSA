// Problem: Check if two binary trees are identical or not
// Time Complexity: O(n), where n is the number of nodes in the trees
// Space Complexity: O(h), where h is the height of the trees (due to recursion stack)

// Approach: We can use a recursive approach to check if two binary trees are identical. We will compare the values of the nodes and recursively check their left and right subtrees.

#include <iostream>
#include <queue>
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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == nullptr || q == nullptr){
            return (p==q);
        }

        return (p->val == q->val)
            && isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution solution;

    // Create two identical trees
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    tree2->right->left = new TreeNode(4); // Adding an extra node to make the trees different

    // Check if the trees are identical
    bool result = solution.isSameTree(tree1, tree2);
    cout << "Are the two trees identical? " << (result ? "Yes" : "No") << endl;

    // Clean up memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}