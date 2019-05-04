/*******************
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
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
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        convertBST(root -> right);
        sum += root -> val;
        root -> val = sum;
        convertBST(root -> left);
        
        return root;
    }    
};

int main() {
    return 0;
}