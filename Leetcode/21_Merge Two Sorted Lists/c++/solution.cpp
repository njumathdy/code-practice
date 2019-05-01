/*******************
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        
        ListNode* dummy = new ListNode(0), *cur = dummy;
        
        while(l1 != nullptr && l2 != nullptr) {
            if(l1 -> val <= l2 -> val) {
                cur -> next = l1;
                cur = l1;
                l1 = l1 -> next;
            } else {
                cur -> next = l2;
                cur = l2;
                l2 = l2 -> next;
            }
        }
        if(l1 != nullptr) 
            cur -> next = l1;
        else
            cur -> next = l2;
        
        return dummy -> next;
    }
};

int main() {
    return 0;
}