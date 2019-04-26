/*******************
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == nullptr)
            return ans;
        
        queue<TreeNode*> q;
        vector<int> t;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* p = q.front();
                q.pop();
                t.push_back(p->val);
                
                if(p -> left != nullptr)
                    q.push(p->left);
                if(p -> right != nullptr)
                    q.push(p->right);
            }
            ans.push_back(t);
            t.clear();
        }
        
        return ans;
    }
};

int main() {
    return 0;
}