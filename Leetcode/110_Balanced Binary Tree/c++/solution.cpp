/*******************
Given a binary tree, determine if it is height-balanced.
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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return checkBalance(root, height);
    }
    
    bool checkBalance(TreeNode* root, int& height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        if (!checkBalance(root->left, leftHeight)) return false;
        if (!checkBalance(root->right, rightHeight)) return false;
        if ( abs(leftHeight - rightHeight) > 1 ) return false;
        height = max(leftHeight, rightHeight) + 1;
        return true;
    }
};

int main() {
    return 0;
}