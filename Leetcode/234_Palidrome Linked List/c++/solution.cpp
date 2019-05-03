/*******************
Given a singly linked list, determine if it is a palindrome.
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse_list(slow);
        slow = slow->next; // 翻转后的头节点
        while(slow) {
            if(head->val != slow->val)
                return false;

            slow = slow->next;
            head = head->next;
        }
        return true;
    }
private:
    // slow是要翻转的链表头节点的前一个节点
    ListNode *reverse_list(ListNode *slow) {
        ListNode *prev = slow;
        ListNode *cur, *tmp_next = prev->next;
        while(tmp_next) {
            cur = tmp_next;
            tmp_next = cur->next;
            cur->next = prev;
            prev = cur;
        }
        slow->next->next = nullptr;
        return cur;
    }
};

int main() {
    return 0;
}