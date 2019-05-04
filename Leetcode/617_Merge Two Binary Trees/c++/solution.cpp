/*******************
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
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

// recursive
class Solution1 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr && t2 == nullptr)
            return nullptr;
        if(t1 == nullptr)
            return t2;
        if(t2 == nullptr)
            return t1;
        
        t1 -> val += t2 -> val;
        t1 -> left = mergeTrees(t1->left, t2->left);
        t1 -> right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};

// iterative, dfs
class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr)
            return t2;
        if(t2 == nullptr)
            return t1;
        
        stack<pair<TreeNode*, TreeNode*> > s;
        s.push(make_pair(t1, t2));
        pair<TreeNode*, TreeNode*> t;
        
        while(!s.empty()) {
            t = s.top();
            s.pop();
            if(t.first == nullptr || t.second == nullptr)
                continue;
            t.first -> val += t.second -> val;
            if(t.first -> left == nullptr)
                t.first -> left = t.second -> left;
            else {
                s.push(make_pair(t.first -> left, t.second -> left));
            }
            if(t.first -> right == nullptr)
                t.first -> right = t.second -> right;
            else {
                s.push(make_pair(t.first -> right, t.second -> right));
            }
        }
        
        return t1;
    }
};

int main() {
    return 0;
}