/*******************
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
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

void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head -> val << endl;
        head = head -> next;
    }
}

// 从前往后搜索即可
class Solution1 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* p = head;
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;
        ListNode* dummyNode = new ListNode(0);
        dummyNode -> next = head;
        while(p != nullptr && p -> val < x) {
            p = p -> next;
        }

        if(p == nullptr)
            return head;
        if(p == head) {
            p1 = dummyNode;
        } else {
            p1 = head;
            while(p1 -> next != p)
                p1 = p1 -> next;
        }
        
        while(p -> next != nullptr) {
            if(p -> next -> val < x) {
                // cout << "**************" << endl;
                ListNode* t1 = p1 -> next;
                // 这里需要先将p -> next -> next保存下来，后面p -> next调整到前面时会改变p -> next -> next的值
                ListNode* t2 = p -> next -> next; 
                p1 -> next = p -> next;
                p1 -> next -> next = t1;
                p1 = p1 -> next;
                
                p -> next = t2;
            } else {
                p = p -> next;
            }
        }
        
        return dummyNode -> next;
    }
};

int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(4);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(2);
    ListNode* p5 = new ListNode(5);
    ListNode* p6 = new ListNode(2);

    p1 -> next = p2;
    p2 -> next = p3;
    p3 -> next = p4;
    p4 -> next = p5;
    p5 -> next = p6;

    Solution1 sol;
    ListNode* ans = sol.partition(p1, 3);
    printList(ans);

    return 0;
}