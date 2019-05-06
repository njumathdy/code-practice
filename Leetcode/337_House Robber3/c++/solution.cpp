/*******************
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dp
class Solution1 {
public:
    int rob(TreeNode* root) {
        map<TreeNode*, int> m;
        return robSub(root, m);  
    }  
    
    int robSub(TreeNode* node, map<TreeNode*, int>& m) {
        if(node == nullptr)
            return 0;
        
        if(m.find(node) != m.end())
            return m[node];
        
        int val = 0;
        if(node -> left != nullptr)
            val += robSub(node -> left -> left, m) + robSub(node -> left -> right, m);
        if(node -> right != nullptr)
            val += robSub(node -> right -> left, m) + robSub(node -> right -> right, m);
        
        val = max(val + node -> val, robSub(node -> left, m) + robSub(node -> right, m));
        m[node] = val;
        
        return val;    
    }
};

class Solution2 {
public:
    int robtree(TreeNode* root,int &rnext, int &rnow)
    {
        if(!root)return 0;
        int a = 0,b = 0,c = 0,d = 0;
        if(root->left)robtree(root->left, a, b);
        if(root->right)robtree(root->right, c, d);
        rnow = a + c + root->val;
        rnext = max(a,b) + max(c,d);
        return max(rnow,rnext);
    }
    int rob(TreeNode* root) {
        int a = 0,b = 0;
        return robtree(root, a,b);
    }
};

int main() {
    return 0;
}