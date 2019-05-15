/*******************
Given a binary tree, return all root-to-leaf paths.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        dfs(root, s, res);
        return res;
    }
    
    void dfs(TreeNode* node, string s, vector<string>& path) {
        if(node == nullptr) {
            return;
        }
        if(s.size() > 0)
            s += "->";
        s += to_string(node -> val);
        if(node -> left == nullptr && node -> right == nullptr) {
            path.push_back(s);
            return;
        }
        dfs(node -> left, s, path);
        dfs(node -> right, s, path);
    }
};

int main() {
    return 0;
}