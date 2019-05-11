/*******************
Remove all elements from a linked list of integers that have value val.
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy, *cur = head;
        dummy -> next = head;
        while(cur != nullptr) {
            if(cur -> val == val) {
                ListNode* temp = cur;
                cur = cur -> next;
                prev -> next = cur;
                delete(temp);
            } else {
                prev = cur;
                cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};

int main() {
    return 0;
}