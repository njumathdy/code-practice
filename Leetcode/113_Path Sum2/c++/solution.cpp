/*******************
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> path;
        if(root == nullptr)
            return ans;
        
        dfs(ans, path, root, sum);
        return ans;
    }
    
    void dfs(vector<vector<int> >& ans, vector<int>& path, TreeNode* node, int sum) {
        if(node == nullptr)
            return;
        path.push_back(node->val);
        
        if(node->left == nullptr && node->right == nullptr && node->val == sum) 
            ans.push_back(path);
        else {
            dfs(ans, path, node->left, sum - node->val);
            dfs(ans, path, node->right, sum - node->val);
        }
        path.pop_back();
    }
};

int main() {
    return 0;
}