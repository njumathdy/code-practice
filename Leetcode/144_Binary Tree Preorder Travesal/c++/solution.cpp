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

// iterative
class Solution2 {
public: 
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
            auto node = s.top();
            s.pop();
            res.push_back(node -> val);

            if(node -> right) s.push(node -> right);
            if(node -> left) s.push(node -> left);
        }

        return res;
    }
};

int main() {
    return 0;
}