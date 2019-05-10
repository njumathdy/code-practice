/*******************
Given a binary tree, return the preorder traversal of its nodes' values.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
    
    void helper(TreeNode* node, vector<int>& ans) {
        if(node == nullptr)
            return;
        
        ans.push_back(node -> val);
        helper(node -> left, ans);
        helper(node -> right, ans);
    }
};

int main() {
    return 0;
}