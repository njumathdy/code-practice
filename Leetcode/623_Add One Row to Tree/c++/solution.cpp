/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* node = new TreeNode(v);
            node -> left = root;
            return node;
        }
        
        insert(v, root, 1, d);
        return root;
    }
    
    void insert(int val, TreeNode* node, int depth, int n) {
        if(node == nullptr)
            return;
        
        if(depth == n - 1) {
            TreeNode* t = node -> left;
            node -> left = new TreeNode(val);
            node -> left -> left = t;
            t = node -> right;
            node -> right = new TreeNode(val);
            node -> right -> right = t;
        } else {
            insert(val, node -> left, depth+1, n);
            insert(val, node -> right, depth+1, n);
        }
    }
};

int main() {
    return 0;
}