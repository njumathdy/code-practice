/*******************
Given an n-ary tree, return the postorder traversal of its nodes' values.
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

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// recursive
class Solution1 {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        
        return res;
    }
    
    void postorder(Node* root, vector<int>& nums) {
        if(root == nullptr)
            return;
        
        for(auto child : root -> children)
            postorder(child, nums);
            
        nums.push_back(root -> val);
    }
};

class Solution2 {
public:
    vector<int> postorder(Node* root) {
        if(root == nullptr) return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()) {
            Node* temp=stk.top();
            stk.pop();
            for(int i = 0; i < temp->children.size(); i++) 
                stk.push(temp->children[i]);
            res.push_back(temp->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }  
};



int main() {
    return 0;
}