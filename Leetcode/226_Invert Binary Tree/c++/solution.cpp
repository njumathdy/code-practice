/*******************
Invert a binary tree.
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

// recursive
class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        TreeNode* left = root -> left, *right = root -> right;
        root -> left = right;
        root -> right = left;
        invertTree(left);
        invertTree(right);
        
        return root;
    }
};

// iterative
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            swap(cur->left, cur->right);
            if(cur->left != nullptr)
                q.push(cur->left);
            if(cur->right != nullptr)
                q.push(cur->right);
        }
        
        return root;
    }
};

int main() {
    return 0;
}