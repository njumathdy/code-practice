/*******************
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    string tree2str(TreeNode* t) {
        if(t == nullptr)
            return "";
        
        if(t -> left == nullptr && t -> right ==nullptr)
            return to_string(t -> val) + "";
        if(t -> right == nullptr)
            return to_string(t -> val) + "(" + tree2str(t -> left) + ")";
        
        return to_string(t -> val) + "(" + tree2str(t -> left) + ")(" + tree2str(t -> right) + ")";
    }
};

class Solution2 {
public:
    string tree2str(TreeNode* t){
        string s = "";
        if(t==NULL) return s;
        set<TreeNode*> visited_node;
        stack<TreeNode*> stack_node;
        stack_node.push(t);
        while(!stack_node.empty()){
            t = stack_node.top();
            if(visited_node.find(t)==visited_node.end()) {
                s = s + "(" + to_string(t->val);
                visited_node.insert(t);
                if(t->right != NULL) stack_node.push(t->right);
                if(t->left != NULL) stack_node.push(t->left);
                if(t->left == NULL && t->right != NULL){
                    s += "()";
                } 
            } else {
                s += ")";
                stack_node.pop();
            }
        }
        s.erase(s.begin()+0);
        s.erase(s.end()-1);
        return s;
    }
};

int main() {
    return 0;
}