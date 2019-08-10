/*******************
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. 
These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. 
You are given the head of the first level of the list.
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
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr)
            return nullptr;
        
        Node* h = head;
        for(; h; h = h -> next) {
            if(h -> child) {
                Node* temp = h -> next;
                h -> next = h -> child;
                h -> child -> prev = h;
                h -> child = nullptr;
                Node* q = h;
                while(q -> next)
                    q = q -> next;
                q -> next = temp;
                if(temp)
                    temp -> prev = q;
            }
        }
        
        return head; 
    }       
};

int main() {
    return 0;
}