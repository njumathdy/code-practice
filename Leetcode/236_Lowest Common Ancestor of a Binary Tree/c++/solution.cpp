/*******************
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

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

// recursive
class Solution1 {
public:
    TreeNode* ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recursive(root, p, q);
        return ans;
    }
    
    bool recursive(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node == nullptr)
            return false;
        
        int left = recursive(node -> left, p, q) ? 1 : 0;
        int right = recursive(node -> right, p, q) ? 1 : 0;
        int mid = (node == p || node == q) ? 1 : 0;
        
        if(mid + left + right >= 2)
            ans = node;
        
        return (mid + left + right > 0);     
    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root||root == q||root == p) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
		if (left && right)
            return root;
        
		return left ? left : right;
	}
};

int main() {
    return 0;
}