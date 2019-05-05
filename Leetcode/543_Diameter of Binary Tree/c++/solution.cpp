/*******************
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            res = max(res, height(p->left)+height(p->right));
            if(p -> left != nullptr)
                q.push(p -> left);
            if(p -> right != nullptr)
                q.push(p -> right);
        }
        
        return res;
    }
    
    int height(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
};

class Solution2 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int res = 1;
        height(root, res);
        
        return res - 1;
    }
    
    int height(TreeNode* root, int& ans) {
        if(root == nullptr)
            return 0;
        
        int l = height(root -> left, ans);
        int r = height(root -> right, ans);
        ans = max(ans, l+r+1);
        return max(l, r) + 1;
    }
};

int main() {
    return 0;
}