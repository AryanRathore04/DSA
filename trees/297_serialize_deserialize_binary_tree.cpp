// Leetcode 297. Serialize and Deserialize Binary Tree
// This is a C++ implementation of the Codec class that provides methods to serialize and deserialize a binary tree. The serialization process converts the tree into a string representation, while the deserialization process reconstructs the tree from the string.

// Time Complexity: O(n), where n is the number of nodes in the binary tree. Both serialization and deserialization processes traverse all nodes in the tree once.
// Space Complexity: O(n), where n is the number of nodes in the binary tree.

// Approach: The serialization is done using level order traversal (BFS) with a queue. Each node's value is appended to a string, and null nodes are represented by a special character (e.g., "#"). During deserialization, the string is split, and the tree is reconstructed using a queue to keep track of the nodes.

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();

            if(curNode == NULL) s.append("#,");
            else s.append(to_string(curNode->val) + ',');
            if(curNode != NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));