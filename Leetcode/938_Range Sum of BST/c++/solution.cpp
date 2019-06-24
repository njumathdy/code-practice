/*******************
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        dfs(root, L, R, res);
        
        return res;
    }
    
    void dfs(TreeNode* node, int L, int R, int& res) {
        if(node == nullptr)
            return;
        if(node -> val >= L && node -> val <= R) {
            res += node -> val;
            dfs(node -> left, L, R, res);
            dfs(node -> right, L, R, res);
        } else if(node -> val < L) {
            dfs(node -> right, L, R, res);
        } else {
            dfs(node -> left, L, R, res);
        }     
    }
};

int main() {
    return 0;
}