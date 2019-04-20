/*******************
Given a sorted linked list, 
delete all duplicates such that each element appear only once.
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

// 代码不够简洁
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* dummyNode = new ListNode(0);
        ListNode* p = head;
        dummyNode -> next = p;
        int val = p -> val;
        head = head -> next;
        while(head != nullptr) {
            if(head -> val != val) {
                p -> next = head;
                p = p -> next;
                val = head -> val;
            }
            head = head -> next;
        }
        p -> next = nullptr;
        return dummyNode -> next;
    }
};

// 代码更简洁，且所需空间为O(1)
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr != nullptr && curr -> next != nullptr) {
            if(curr -> next -> val == curr -> val)
                curr -> next = curr -> next -> next;
            else
                curr = curr -> next;
        }
        return head;
    }
};

int main() {
    return 0;
}