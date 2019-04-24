/*******************
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode* a, const ListNode* b) -> bool { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>  pq(comp);
        
        for(auto l:lists) {
            if(l) pq.push(l);
        }
        if(pq.empty()) return nullptr;
        
        ListNode* head = pq.top();
        pq.pop();
        if(head->next) pq.push(head->next);
        ListNode* curr = head;
        
        while(!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next; 
            if(curr->next) pq.push(curr->next);
        }
        return head;
    }
};

int main() {
    return 0;
}