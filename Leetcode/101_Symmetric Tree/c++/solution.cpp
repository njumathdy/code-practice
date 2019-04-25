/*******************
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
    bool isSymmetric(TreeNode* root) {
        return isSymmetrical(root, root);
    }
    
    bool isSymmetrical(TreeNode* p1, TreeNode* p2) {
        if(p1 == nullptr && p2 == nullptr)
            return true;
        if(p1 == nullptr || p2 == nullptr)
            return false;
        
        if(p1->val != p2->val)
            return false;
        
        return isSymmetrical(p1->left, p2->right) && isSymmetrical(p1->right, p2->left);
    }
};

// iterative
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        queue<TreeNode*> q;
        q.push(root); q.push(root);
        while(!q.empty()) {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if(t1 == nullptr && t2 == nullptr)
                continue;
            if(t1 == nullptr || t2 == nullptr)
                return false;
            if(t1->val != t2->val)
                return false;
            q.push(t1->left); q.push(t2->right);
            q.push(t1->right); q.push(t2->left);
        }
        
        return true;
    }  
};

int main() {
    return 0;
}