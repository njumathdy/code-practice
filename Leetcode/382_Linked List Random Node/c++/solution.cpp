/*******************
Given a singly linked list, return a random node's value from the linked list. 
Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? 
Could you solve this efficiently without using extra space?
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

// reservoir sampling
class Solution {
private:
    ListNode* node;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        node = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = 0, ans = -1;
        ListNode* temp = node;
        while(temp != nullptr) {
            if(n == 0) {
                ans = temp -> val;
                n++;
            } else {
                n++;
                if(rand() % n == 0) {
                    ans = temp -> val;
                }
            }
            temp = temp -> next;
        }
        return ans;
    }
};

int main() {
    return 0;
}