/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <exception>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        
        if(head->next == nullptr)
            return head;
        
        ListNode* temp1 = head->next;
        ListNode* temp2 = temp1->next;
        
        temp1->next = head;
        head->next = swapPairs(temp2);
        
        return temp1;   
    }
};