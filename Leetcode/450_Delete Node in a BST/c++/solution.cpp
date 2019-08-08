/*******************
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        
        if(root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        } else if(root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        } else {
            if(root -> right == nullptr)
                return root -> left;
            if(root -> left == nullptr)
                return root -> right;
            
            TreeNode* node = findMin(root -> right);
            root -> val = node -> val;
            root -> right = deleteNode(root -> right, root -> val);
        }
        
        return root;
    }
    
    TreeNode* findMin(TreeNode* node) {
        if(node == nullptr)
            return nullptr;
        
        while(node -> left != nullptr)
            node = node -> left;
        
        return node;
    }    
};

int main() {
    return 0;
}