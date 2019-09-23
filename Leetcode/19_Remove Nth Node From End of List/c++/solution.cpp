/*******************
Given a linked list, remove the n-th node from the end of list and return its head.
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

// two pass
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int count = 0;
        while(cur) {
            count++;
            cur = cur -> next;
        }
        if(n > count) return nullptr;
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        
        ListNode* pre = dummy; cur = head;
        count = count - n;
        while(count) {
            pre = cur;
            cur = cur -> next;
            
            count--;
        }
        pre -> next = cur -> next;
        
        return dummy -> next;
    }
};

// one pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        
        ListNode* first = dummy, *second = dummy;
        for(int i = 0; i <= n; i++)
            second = second -> next;
        
        while(second) {
            first = first -> next;
            second = second -> next;
        }
        first -> next = first -> next -> next;
        
        return dummy -> next;
    }
};

int main() {
    return 0;
}