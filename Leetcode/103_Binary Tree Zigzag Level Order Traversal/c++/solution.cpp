/*******************
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, 
then right to left for the next level and alternate between).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 也可以用栈来实现
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == nullptr)
            return ans;
        
        bool flag = true;
        vector<int> temp;
        deque<TreeNode*> q;
        q.push_back(root);
        
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* p = flag ? q.front() : q.back();
                if(flag)
                    q.pop_front();
                else
                    q.pop_back();
                temp.push_back(p -> val);
                
                if(flag) {
                    if(p->left != nullptr)
                        q.push_back(p->left);
                    if(p->right != nullptr)
                        q.push_back(p->right);
                } else {
                    if(p->right != nullptr)
                        q.push_front(p->right);
                    if(p->left != nullptr)
                        q.push_front(p->left);
                }
            }
            flag = !flag;
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
    }
};

int main() {
    return 0;
}