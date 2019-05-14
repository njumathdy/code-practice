/*******************
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
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
    void deleteNode(ListNode* node) {
        if(node -> next == nullptr)
            node = nullptr;
        
        ListNode* after = node -> next;
        int temp = after -> val;
        after -> val = node -> val;
        node -> val = temp;
        node -> next = after -> next;
        delete(after);
    }
};

int main() {
    return 0;
}