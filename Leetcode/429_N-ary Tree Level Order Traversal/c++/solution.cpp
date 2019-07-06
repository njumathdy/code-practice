/*******************
Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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

class Solution {
public:
    vector<vector<int> > levelOrder(Node* root) {
        vector<vector<int> > res;
        if(root == nullptr)
            return res;
        
        queue<Node*> q;
        vector<int> temp;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                Node* p = q.front();
                q.pop();
                temp.push_back(p -> val);
                
                for(Node* child : p ->children) {
                    if(child != nullptr)
                        q.push(child);
                }
            }
            
            res.push_back(temp);
            temp.clear();
        }
        
        return res;
    }
};

int main() {
    return 0;
}