/*******************
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return;
        
        ListNode* slow = head, *fast = head;
        while(fast != nullptr && fast -> next != nullptr && fast -> next -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode* second = slow -> next;
        slow -> next = nullptr;
        
        second = reverse(second);
        head = merge(head, second);
        return;
    }
    
    ListNode* reverse(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode *cur = head, *pre = nullptr, *temp;
        
        while(cur != nullptr) {
            temp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = temp;
        }
        
        return pre;
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int i = 0;
        while(head1 && head2) {
            if(i % 2 == 0) {
                cur -> next = head1;
                head1 = head1 -> next;
                cur = cur -> next;
            } else {
                cur -> next = head2;
                head2 = head2 -> next;
                cur = cur -> next;
            }
            i++;   
        }
        if(head1) 
            cur -> next = head1;
        if(head2)
            cur -> next = head2;
        
        ListNode* res = dummy -> next;
        delete(dummy);
        return res;
    }
};

int main() {
    return 0;
}