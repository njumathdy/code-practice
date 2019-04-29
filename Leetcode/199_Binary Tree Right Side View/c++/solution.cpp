/*******************
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
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

// bfs
class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* p;
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0; i < n; i++) {
                p = q.front();
                q.pop();
                if(p -> left != nullptr)
                    q.push(p->left);
                if(p -> right != nullptr)
                    q.push(p->right);
                if(i == n-1)
                    ans.push_back(p->val);
            }
        }
        
        return ans;
    }
};

// dfs
class Solution2 {
public:
    vector<int> res;
    int dfs(TreeNode* cur, int curD, int maxD) {
        // 回溯
        if (cur == nullptr) return curD-1;
        if (curD > maxD) {
            maxD = curD;
            res.push_back(cur->val);
        }
        // 一开始都是向右搜索
        maxD = max(maxD, dfs(cur->right, curD + 1, maxD));
        // 向左搜索
        return max(maxD, dfs(cur->left, curD + 1, maxD));
    }
    
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0, -1);
        return res;
    }
};

int main() {
    return 0;
}