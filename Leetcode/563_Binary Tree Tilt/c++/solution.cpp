/*******************
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. 
Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.
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
    int findTilt(TreeNode* root) {
        int res = 0;
        
        tilt(root, res);
        
        return res;
    }
    
    void tilt(TreeNode* root, int& res) {
        if(root == nullptr)
            return;
        
        int sum1 = treeSum(root -> left);
        int sum2 = treeSum(root -> right);
        
        res += sum1 > sum2 ? (sum1 - sum2) : (sum2 - sum1);
        
        tilt(root -> left, res);
        tilt(root -> right, res);
    }
    
    int treeSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int sum = root -> val;
        sum += treeSum(root -> left);
        sum += treeSum(root -> right);
        
        return sum;
    }
};

int main() {
    return 0;
}