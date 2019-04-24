/*******************
Given an integer n, 
generate all structurally unique BST's (binary search trees) that store values 1 ... n.
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        else
            return generateTree(1, n);
    }
    
    vector<TreeNode*> generateTree(int from, int to) {
        vector<TreeNode*> ret;
        if(to - from < 0) ret.push_back(0);
        if(to - from == 0) ret.push_back(new TreeNode(from));
        if(to - from > 0) {
            for(int i=from; i<=to; i++) {
                vector<TreeNode*> l = generateTree(from, i-1);
                vector<TreeNode*> r = generateTree(i+1, to);

                for(int j=0; j<l.size(); j++)
                {
                    for(int k=0; k<r.size(); k++)
                    {
                        TreeNode * h = new TreeNode (i);
                        h->left = l[j];
                        h->right = r[k];
                        ret.push_back(h);
                    }
                }
            }
        }
        return ret;
    }
};

// Leetcode solution: iterative
class Solution2 {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees_1(n);
    }
    
    TreeNode * clone(TreeNode *old_root)
    {
        if(old_root == NULL) return NULL;
        TreeNode *new_root = new TreeNode(old_root->val);
        new_root->left = clone(old_root->left);
        new_root->right = clone(old_root->right);
        
        return new_root;
    }
    
    vector<TreeNode*> generateTrees_1(int n)
    {
        if(n <= 0) return {};
        vector<TreeNode *> results;
        vector<TreeNode *> previous_result(1, nullptr);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < previous_result.size(); ++j)
            {
                // The nth node is the new root
                TreeNode *new_root = new TreeNode(i);
                TreeNode *new_left_subtree = clone(previous_result[j]);
                new_root->left = new_left_subtree;
                results.push_back(new_root);
                
                // traverse the old tree, use new node to replace the old right child
                TreeNode *root = previous_result[j];
                TreeNode *root_temp = root;
                while(root_temp != nullptr)
                {
                    TreeNode *old_right_subtree = root_temp->right;
                    TreeNode *new_right_subtree = new TreeNode(i);
                    new_right_subtree->left = old_right_subtree;
                    root_temp->right = new_right_subtree;
                    TreeNode *new_tree = clone(root);
                    results.push_back(new_tree);
                    
                    // 回溯到之前的状态
                    root_temp->right = old_right_subtree;
                    delete new_right_subtree;
                    new_right_subtree = nullptr;
                    root_temp = root_temp->right;
                }
            }
            
            swap(results, previous_result);
            results.clear();
        }
              
        return previous_result;
    }
};

int main() {
    bool a = NULL;
    if(a)
        cout << "true" << endl;
    else
    {
        cout << "false" << endl;
    }
    
    return 0;
}