/*******************
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursion
class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr || q == nullptr)
            return false;
        if(p -> val != q -> val)
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);   
    }
};

// iteration
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr || q == nullptr)
            return false;
        stack<TreeNode*> s1, s2;
        s1.push(p);
        s2.push(q);
        while(!s1.empty() && !s2.empty()) {
            TreeNode* p1 = s1.top();
            TreeNode* q1 = s2.top();
            s1.pop(); s2.pop();
            if(p1->val != q1->val)
                return false;
            if(p1->left != nullptr)
                s1.push(p1->left);
            if(q1->left != nullptr)
                s2.push(q1->left);
            if(s1.size() != s2.size())
                return false;
            if(p1->right != nullptr)
                s1.push(p1->right);
            if(q1->right != nullptr)
                s2.push(q1->right);
            if(s1.size() != s2.size())
                return false;
        }
        
        return s1.size() == s2.size();
    }
};

int main() {
    return 0;
}