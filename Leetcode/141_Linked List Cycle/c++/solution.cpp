/*******************
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. 
If pos is -1, then there is no cycle in the linked list.
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

// two pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head -> next == nullptr)
            return false;
        
        ListNode *slow = head, *fast = head -> next;
        while(slow != nullptr && fast != nullptr) {
            if(slow == fast)
                return true;
            slow = slow -> next;
            if(fast -> next != nullptr) {
                fast = fast -> next -> next;
            } else
                return false;
        }
        
        return false;
    }
};

int main() {
    return 0;
}