/*******************
Given a linked list, rotate the list to the right by k places, where k is non-negative.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        
        int n = 1;
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = head;
        ListNode* tail;
        ListNode* curr;
        while(p -> next != nullptr) {
            n++;
            p = p -> next;
        }
        tail = p;
        
        k %= n;
        if(k == 0)
            return head;
        
        p = head;
        for(int i = 1; i <= n-k; i++) {
            curr = p;
            p = p -> next;
        }
        curr -> next = nullptr;
        dummyHead -> next = p;
        tail -> next = head;
        return dummyHead -> next;   
    }
};

int main() {
    return 0;
}