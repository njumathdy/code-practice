/*******************
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// iterative
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int ans = 0;
        while(!q.empty()) {
            ans++;
            
            for(int i = 0, n = q.size(); i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
            
                if(t -> left != nullptr)
                    q.push(t->left);
                if(t -> right != nullptr)
                    q.push(t->right);    
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}