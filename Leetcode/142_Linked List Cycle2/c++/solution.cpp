/*******************
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
Note: Do not modify the linked list.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) 
            return nullptr;
        ListNode* slow = head;
        ListNode* quick = head -> next;
        ListNode* meetNode = nullptr;
        while(slow != nullptr && quick != nullptr) {
            if(slow == quick) {
                meetNode = slow;
                break;
            }
            slow = slow -> next;
            quick = quick -> next;
            if(quick != nullptr)
                quick = quick -> next;        
        }
        if(meetNode == nullptr)
            return nullptr;
        
        ListNode* temp = meetNode;
        int count = 1;
        while(temp -> next != meetNode) {
            temp = temp -> next;
            count++;
        }
        ListNode* node1 = head;
        ListNode* node2 = head;
        for(int i = 0; i < count; i++)
            node1 = node1 -> next;
        while(node1 != node2) {
            node1 = node1 -> next;
            node2 = node2 -> next;
        }
        return node1;
    }
};

int main() {
    return 0;
}