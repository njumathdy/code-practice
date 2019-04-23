/*******************
Given a binary tree, return the inorder traversal of its nodes' values.
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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursive
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        recursive(root, ans);
        return ans;        
    }
    
    void recursive(TreeNode* root, vector<int>& ans) {
        if(root != nullptr) {
            if(root -> left != nullptr)
                recursive(root->left, ans);
            ans.push_back(root->val);
            if(root -> right != nullptr)
                recursive(root->right, ans);
        }
    }
};

// iterative
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> ans;
        
        TreeNode* curr = root;
        while(curr != nullptr || !stack.empty()) {
            while(curr != nullptr) {
                stack.push(curr);
                curr = curr -> left;
            }
            curr = stack.top();
            stack.pop();
            ans.push_back(curr->val);
            curr = curr -> right;       
        }
        return ans;
    }   
};

int main() {
    return 0;
}