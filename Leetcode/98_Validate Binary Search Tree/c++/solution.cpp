/*******************
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursive
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};

// iterative
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        stack<TreeNode*> stack1;
        stack<int> val1;
        stack<int> val2;
        stack1.push(root);
        val1.push(NULL); val2.push(NULL);
        
        while(!stack1.empty()) {
            TreeNode* curr = stack1.top();
            stack1.pop();
            int low = val1.top();
            int up = val2.top();
            val1.pop(); val2.pop();
            
            if(curr -> left != nullptr) {
                if(curr -> val > curr -> left -> val) {
                    if(low != NULL && curr->left->val <= low)
                        return false;
                    stack1.push(curr->left);
                    val1.push(low); val2.push(curr->val);
                } else 
                    return false;   
            }
            
            if(curr -> right != nullptr) {
                if(curr -> val < curr -> right -> val) {
                    if(up != NULL && curr->right->val >= up)
                        return false;
                    stack1.push(curr->right);
                    val1.push(curr->val); val2.push(up);
                } else
                    return false;
            }
        }
        
        return true;
    }   
};

int main() {
    return 0;
}