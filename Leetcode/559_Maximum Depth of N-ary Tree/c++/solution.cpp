/*******************
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

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
    int maxDepth(Node* root) {
       return height(root); 
    }
    
    int height(Node* root) {
        if(root == nullptr)
            return 0;
        
        int hei = 1;
        for(auto node : root -> children)
            hei = max(hei, 1+height(node));
        
        return hei;
    }
};

int main() {
    return 0;
}