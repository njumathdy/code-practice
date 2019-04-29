/*******************
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>

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
    int maxPathSum(TreeNode* root) {
        int bestOverAll = INT_MIN;
        helper(root, bestOverAll);
        
        return bestOverAll; 
    }
    
    int helper(TreeNode* node, int& bestOverAll) {
        if(node == nullptr)
            return 0;
        
        auto left = max(0, helper(node -> left, bestOverAll));
        auto right = max(0, helper(node -> right, bestOverAll));
        
        bestOverAll = max(bestOverAll, node->val + left + right);
        
        // 向上传递
        return max(node->val+left, node->val + right);
    }   
};

int main() {
    return 0;
}