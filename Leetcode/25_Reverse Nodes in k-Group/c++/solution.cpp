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
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
  
class Solution {
public:
    int lengthOfList(ListNode* head) {
        int length = 0;
        while(head != nullptr) {
            length++;
            head = head -> next;
        }
        
        return length;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        
        if(lengthOfList(head) < k)
            return head;
        
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* reversedHead = nullptr;
        for(int i = 0; i < k; i++) {
            ListNode* pNext = current -> next;
                
            current -> next = prev;
            
            prev = current;
            current = pNext;   
        }
        head -> next = reverseKGroup(current, k);
        
        return prev;
    }
};