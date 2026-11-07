// Problem: Serialize and Deserialize Binary Tree
// Given a binary tree, design an algorithm to serialize and deserialize it.

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Time Complexity: O(n), where n is the number of nodes in the binary tree. We visit each node once during serialization and deserialization.
// Space Complexity: O(n), where n is the number of nodes in the binary tree. The space used for the queue during serialization and deserialization can grow up to the number of nodes in the tree.

// Approach: We can use level order traversal (BFS) to serialize the binary tree. We will use a queue to traverse the tree level by level and append the values of the nodes to a string. For null nodes, we will append a special character (e.g., "#") to indicate that there is no node at that position. During deserialization, we will split the serialized string and reconstruct the binary tree using a queue to keep track of the nodes.

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

class Solution {
    public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root){
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(curNode == NULL) s.append("#,"); // What is append? It is used to append the value of the current node to the string s. If the current node is NULL, it appends "#," to indicate a null node in the serialized string.
            else  s.append(to_string(curNode->val) + ',');
            if(curNode != NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str)); // What is stoi? It is a function that converts a string to an integer. In this case, it converts the string representation of the root node's value to an integer and creates a new TreeNode with that value.
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the binary tree
    string serializedTree = solution.serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    // Deserialize the string back to a binary tree
    TreeNode* deserializedRoot = solution.deserialize(serializedTree);
    cout << "Deserialized Tree Root Value: " << deserializedRoot->val << endl;

    return 0;
}