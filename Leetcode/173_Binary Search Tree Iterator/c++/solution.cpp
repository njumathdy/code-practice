/*******************
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        find_left(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if(top -> right != nullptr) 
            find_left(top -> right);
        
        return top -> val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty())
            return false;
        return true;
    }
    
    void find_left(TreeNode* node) {
        TreeNode* p = node;
        while(p != nullptr) {
            st.push(p);
            p = p -> left;
        }
    }
};

int main() {
    return 0;
}