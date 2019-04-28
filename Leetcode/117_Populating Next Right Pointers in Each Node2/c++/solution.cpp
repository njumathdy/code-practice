/*******************
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

class Solution2 {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        Node *curr = root, *head = nullptr, *prev = nullptr;
        while(curr != nullptr) {
            while(curr != nullptr) {
                if(curr -> left != nullptr) {
                    if(prev != nullptr)
                        prev -> next = curr -> left;
                    else
                        head = curr -> left;
                    prev = curr -> left;
                }
                if(curr -> right != nullptr) {
                    if(prev != nullptr)
                        prev -> next = curr -> right;
                    else
                        head = curr -> right;
                    prev = curr -> right;    
                }
                curr = curr -> next;
            }
            curr = head;
            head = nullptr;
            prev = nullptr;
        }
        return root;
    }
};

int main() {
    return 0;
}