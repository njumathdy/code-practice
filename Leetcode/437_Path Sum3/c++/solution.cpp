/*******************
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
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

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            helper(t, sum, res);
            if(t -> left != nullptr)
                q.push(t -> left);
            if(t -> right != nullptr)
                q.push(t -> right);
        }
        
        return res;
    }
    
    void helper(TreeNode* node, int target, int& res) {
        if(node == nullptr)
            return;
        if(node -> val == target)
            res++;
        helper(node->left, target - node->val, res);
        helper(node->right, target - node->val, res);
    }
};

int main() {
    return 0;
}