/*******************
Find the sum of all left leaves in a given binary tree.
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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        help(root, false, res);
        
        return res;
    }
    
    void help(TreeNode* node, bool l, int& res) {
        if(node == nullptr)
            return;
        if(node -> left == nullptr && node -> right == nullptr && l == true) {
            res += node -> val;
            return;
        }
        help(node->left, true, res);
        help(node->right, false, res);
    }
};

int main() {
    return 0;
}