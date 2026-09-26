// Leetcode problem: 100. Same Tree
// Time Complexity: O(n), where n is the number of nodes in the tree. We visit each node once.
// Space Complexity: O(h), where h is the height of the tree. This space is used by the recursion stack.

// Approach: We can solve this problem using a recursive approach. We compare the values of the current nodes of both trees. If they are equal, we recursively check their left and right subtrees. If at any point the values are not equal or one of the nodes is null while the other is not, we return false. If we reach the end of both trees without finding any discrepancies, we return true.

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