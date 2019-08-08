/*******************
Given a binary tree, find the leftmost value in the last row of the tree.
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        
        cur.push(root);
        TreeNode* head = nullptr;
        int res;
        while(!cur.empty()) {
            head = cur.front();
            while(!cur.empty()) {
                TreeNode* temp = cur.front();
                cur.pop();
                if(temp -> left)
                    next.push(temp -> left);
                if(temp -> right)
                    next.push(temp -> right);
            }
            if(next.empty()) {
                res = head -> val;
                break;
            } else {
                cur = next;
                while(!next.empty())
                    next.pop();
            }     
        }
        
        return res;
    }
};

int main() {
    return 0;
}