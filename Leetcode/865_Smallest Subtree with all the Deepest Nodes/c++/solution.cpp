/*******************
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.
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

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth[nullptr] = -1;
        dfs(root, nullptr);
        max_depth = -1;
        for(auto iter = depth.begin(); iter != depth.end(); iter++)
            max_depth = max(max_depth, iter -> second);
        
        return answer(root);
    }
    
    void dfs(TreeNode* node, TreeNode* parent) {
        if(node != nullptr) {
            depth[node] = depth[parent] + 1;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
    
    TreeNode* answer(TreeNode* node) {
        if(node == nullptr || depth[node] == max_depth)
            return node;
        
        TreeNode* L = answer(node -> left);
        TreeNode* R = answer(node -> right);
        if(L != nullptr && R != nullptr)
            return node;
        if(L != nullptr)
            return L;
        if(R != nullptr)
            return R;
        return nullptr;
    }
    
private:
    map<TreeNode*, int> depth;
    int max_depth;
};

int main() {
    return 0;
}