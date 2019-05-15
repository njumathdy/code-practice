/*******************
Given a complete binary tree, count the number of nodes.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// simple recursive
class Solution1 {
public:
    int countNodes(TreeNode* root) {
        int res = 0;
        search(root, res);
        return res;
    }
    
    void search(TreeNode* node, int& num) {
        if(node == nullptr)
            return;
        num++;
        search(node -> left, num);
        search(node -> right, num);
    }
};

class Solution2 {
public:
    int countNodes(TreeNode* root) {
        int hLeft = leftHeight(root);
        int hRight = rightHeight(root);
        if (hLeft == hRight)
            return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int leftHeight(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return 1 + leftHeight(root->left);
    }
    int rightHeight(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return 1 + rightHeight(root->right);
    }
};

int main() {
    return 0;
}