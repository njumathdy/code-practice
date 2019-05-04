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
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
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

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;
        stack<TreeNode*> s;
        
        while(!s.empty() || node != nullptr) {
            while(node != nullptr) {
                s.push(node);
                node = node -> right;
            }
            
            node = s.top();
            s.pop();
            sum += node -> val;
            node -> val = sum;
            
            node = node -> left;
        }
        
        return root;
    }    
};

int main() {
    return 0;
}