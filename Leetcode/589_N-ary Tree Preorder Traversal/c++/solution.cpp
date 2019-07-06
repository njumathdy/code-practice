/*******************
Given an n-ary tree, return the preorder traversal of its nodes' values.
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
    vector<int> preorder(Node* root) {
        vector<int> res = {};
        preorder(root, res);
        
        return res;
    }
    
    void preorder(Node* root, vector<int>& nums) {
        if(root == nullptr)
            return;
        nums.push_back(root -> val);
        for(auto child : root -> children) {
            preorder(child, nums);
        }
    }
};

// iterative
class Solution2 {
public:
    vector<int> preorder(Node* root) {
        vector<int> res = {};
        if(root == nullptr)
            return res;
        
        stack<Node*> s;
        s.push(root);
        
        while(!s.empty()) {
            Node* node = s.top();
            s.pop();
            res.push_back(node -> val);
            
            for(int i = node -> children.size() - 1; i >= 0; --i) {
                if(node -> children[i] != nullptr)
                    s.push(node -> children[i]);
            }
        }
        
        return res;
    }  
};

int main() {
    return 0;
}