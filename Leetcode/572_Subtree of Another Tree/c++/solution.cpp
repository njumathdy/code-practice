/*******************
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. 
A subtree of s is a tree consists of a node in s and all of this node's descendants. 
The tree s could also be considered as a subtree of itself.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isEqual(s, t))
            return true;
        
        if(s == nullptr)
            return false;
        
        return isSubtree(s -> left, t) || isSubtree(s -> right, t);
    }
    
    bool isEqual(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr)
            return true;
        
        if(s == nullptr || t == nullptr)
            return false;
        
        if(s -> val != t -> val)
            return false;
        
        return isEqual(s -> left, t -> left) && isEqual(s -> right, t -> right);
    }
};

int main() {
    return 0;
}