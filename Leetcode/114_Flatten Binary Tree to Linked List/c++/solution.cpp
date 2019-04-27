/*******************
Given a binary tree, flatten it to a linked list in-place.
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

// iterative
class Solution1 {
public:
    void flatten(TreeNode *root) {
	    while (root) {
		    if (root->left && root->right) {
			    TreeNode* t = root->left;
			    while (t->right)
				    t = t->right;
			    t->right = root->right; // Morris traversal
		    }

            if(root->left)
		        root->right = root->left;
		    root->left = nullptr;
		    root = root->right;
	    }
    }
};

// recursive
class Solution2 {
public:
    void flatten(TreeNode* root) {
        if(!root)return ;
        if(root->left)
            flatten(root->left);
        if(root->right)
            flatten(root->right);
        
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while(root->right)
            root=root->right;
        root->right = tmp;
    }
};

int main() {
    return 0;
}