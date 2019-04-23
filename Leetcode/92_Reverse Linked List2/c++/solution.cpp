/*******************
Reverse a linked list from position m to n. Do it in one-pass.
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

// my code: not clean enough
class Solution1 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || m == n)
            return head;
        
        int i = 1;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;
        while(i < m) {
            prev = curr;
            curr = curr -> next;
            i++;
        } 
        p1 = prev == nullptr ? new ListNode(0) : prev;
        p2 = curr;
        while(i <= n) {
            ListNode* next = curr -> next;
            if(i == n) {
                p2 -> next = next;
                p1 -> next = curr;
            }
            
            curr -> next = prev;
            prev = curr;
            curr = next; 
            i++;
        }
        if(m == 1)
            return prev;
        else
            return head;
    }
};

// 十分简洁：每次循环将下一个节点重置与指定节点前面
class Solution2 {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return dummy -> next;
   }
};

int main() {
    return 0;
}