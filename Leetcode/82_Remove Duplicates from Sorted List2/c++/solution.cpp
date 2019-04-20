/*******************
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        int duplicate;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                duplicate = cur->next->val;
                while (cur->next && cur->next->val == duplicate) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    return 0;
}