/*******************
You need to find the largest value in each row of a binary tree.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res = {};
        if(root == nullptr)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        int maxn;
        while(!q.empty()) {
            int n = q.size();
            maxn = INT_MIN;
            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                maxn = max(maxn, temp -> val);
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
            }
            res.push_back(maxn);
        }
        
        return res;
    }
};

int main() {
    return 0;
}