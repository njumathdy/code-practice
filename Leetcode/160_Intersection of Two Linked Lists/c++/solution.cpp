/*******************
Write a program to find the node at which the intersection of two singly linked lists begins.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        
        int l1 = 0, l2 = 0;
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1 != nullptr) {
            l1++;
            cur1 = cur1 -> next;
        }
        while(cur2 != nullptr) {
            l2++;
            cur2 = cur2 -> next;
        }
        if(l2 > l1) {
            swap(headA, headB);
            swap(l1, l2);
        }
        int diff = l1 - l2;
        while(diff > 0) {
            headA = headA -> next;
            diff--;
        }
        while(headA != nullptr && headB != nullptr) {
            if(headA == headB)
                return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        
        return nullptr;
    }
};

int main() {
    return 0;
}