/*******************
Sort a linked list using insertion sort.
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

class Solution1 {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode *cur = head -> next;
        
        dummy -> next = head;
        while(cur != nullptr) {
            ListNode* temp = dummy -> next, *pre = dummy;
            while(temp != cur && temp -> val < cur -> val) {
                pre = temp;
                temp = temp -> next;
            }
            if(temp == cur) {
                cur = cur -> next;
            } else {
                pre -> next = cur;
                ListNode* next = cur -> next;
                cur -> next = temp;
                while(temp -> next != cur)
                    temp = temp -> next;
                temp -> next = next;
                cur = next;
            }
        }
        return dummy -> next;
    }
};

class Solution2 {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *p = head;
        while(p && p->next) {
            if(p->next->val >= p->val) {
                p = p->next;
                continue;
            }
            else {
                ListNode* tmp = p->next;
                ListNode* insert = newHead;
                while(insert->next && insert->next->val < tmp->val) insert = insert->next;
                p->next = tmp->next;
                tmp->next = insert->next;
                insert->next = tmp;
            }
        }
        return newHead->next;
    }
};

int main() {
    return 0;
}