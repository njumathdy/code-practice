/*******************
Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* reversedHead = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(curr != nullptr) {
            ListNode* next = curr -> next;
            if(next == nullptr)
                reversedHead = curr;
            
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return reversedHead;
    }
};

int main() {
    return 0;
}