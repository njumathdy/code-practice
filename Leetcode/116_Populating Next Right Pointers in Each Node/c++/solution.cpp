/*******************
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
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

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// my solution
class Solution1 {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        
        queue<Node*> q;
        q.push(root);
        Node* curr, *prev = nullptr;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                curr = q.front();
                q.pop();
                if(prev != nullptr)
                    prev -> next = curr;
                if(curr -> left != nullptr) 
                    q.push(curr -> left);
                if(curr -> right != nullptr)
                    q.push(curr -> right);
                
                if(i == n - 1)
                    prev = nullptr;
                else
                    prev = curr;
            }
        }
        return root;
    }
};

// Leetcode优秀解法，利用堆的思想
class Solution2 {
public:
    void connect(Node *root) {
        if (!root) return;
        vector<pair<Node*, int> > levels;
        
        levels.push_back(make_pair(root, 0));
        int step = 0;
        while (step < levels.size()) {
            
            Node* temp = levels[step].first;
            int level = levels[step++].second;
            
            if (temp->left) levels.push_back(make_pair(temp->left, level + 1));
            if (temp->right) levels.push_back(make_pair(temp->right, level + 1));
        }
        
        for (int i = 1; i < levels.size(); ++i) 
            if (levels[i - 1].second == levels[i].second) 
                levels[i - 1].first->next = levels[i].first;
    }
};

// recursive
class Solution3 {
public:
    void connect(Node *root) 
    {
        if(root == nullptr)
            return;
        
        if(root->left)
            root->left->next = root->right;
        
        if(root->right)
        {
            if(root->next)
                root->right->next = root->next->left;
            else
                root->right->next = nullptr;
        }
        
        connect(root->left);
        connect(root->right);
        
    }
};

int main() {
    return 0;
}