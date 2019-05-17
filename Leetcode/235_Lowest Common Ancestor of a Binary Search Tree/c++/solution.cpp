/*******************
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return root;
        
        if(p == nullptr)
            return q;
        if(q == nullptr)
            return p;
        
        if(p == root)
            return p;
        if(q == root)
            return q;
        
        int f1 = (p -> val <= root -> val);
        int f2 = (q -> val <= root -> val);
        
        if(f1 ^ f2)
            return root;
        
        if(f1)
            return lowestCommonAncestor(root -> left, p, q);
        else
            return lowestCommonAncestor(root -> right, p, q);
    }
};

int main() {
    return 0;
}