/*******************
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

// using hashtable
class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes; // <orig, deep copy>

        // loop through nodes
        Node* tailOrig = head;
        Node* preHead = new Node(-1,nullptr,nullptr);
        Node* tailCopy = preHead;
        while (tailOrig)
        {
            // create a deep copy of the node. Leave random pointer as nullptr
            tailCopy->next = new Node(tailOrig->val, nullptr, nullptr);
            tailCopy = tailCopy->next;
            
            // add to dictionary
            nodes[tailOrig] = tailCopy;
            tailOrig = tailOrig->next;
        }
        
        // loop through nodes again
        tailOrig = head;
        tailCopy = preHead->next;
        while (tailOrig)
        {
            // use dictionary to set the random pointers 
            tailCopy->random = nodes[tailOrig->random];
            tailCopy = tailCopy->next;
            tailOrig = tailOrig->next;
        }
        
        // return head of deep copy
        Node* ans = preHead->next;
        delete preHead;
        return ans;       
    }   
};

class Solution2 {
public:
    Node *copyRandomList(Node *head) {
        if(head==nullptr)
            return nullptr;
        cloneList(head);
        cloneRandom(head);

        return splitList(head);   
    }
    
    void cloneList(Node* head)
    {
        Node* pNode = head;
        while(pNode!=nullptr)
        {
            Node* pClone = new Node(pNode->val, nullptr, nullptr);
            pClone->next = pNode->next;
            pNode->next = pClone;
            pNode = pClone->next;
        }
    }
    
    void cloneRandom(Node* head)
    {
        Node* pNode = head;
        while(pNode!=nullptr && pNode->next!=nullptr)
        {
            if(pNode->random!=nullptr)
                pNode->next->random = pNode->random->next;
            pNode = pNode->next->next;
        }
    }
    Node* splitList(Node* head)//注意原始链表不能被修改，需要复原
    {
        Node* pNode = head;
        Node* pCloneHead = nullptr;
        Node* pCloneNode = nullptr;
        if(pNode!=nullptr)
        {
            pCloneHead = pCloneNode = pNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        while(pNode!=nullptr)
        {
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        return pCloneHead;
    }
};

int main() {
    return 0;
}