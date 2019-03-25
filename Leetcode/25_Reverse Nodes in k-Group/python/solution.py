class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseLinkedList(self, node, previousNode, k):
        start = node
        t1 = node
        t2 = node.next
        nextNode = None
        
        while k > 0 and t2:
            nextNode = t2.next
            t2.next = t1
            t1 = t2
            t2 = nextNode
            k -= 1

        start.next = nextNode
        if previousNode:
            previousNode.next = t1
        if not self.finalStartNode:
            self.finalStartNode = t1
        
        return nextNode, start

    def getLengthOfLinkedList(self, head):
        count = 0
        while head:
            count += 1
            head = head.next
        return count

    def reverseKGroup(self, head, k):
        if not head or k == 1:
            return head

        previousNode = None 
        self.finalStartNode = None
        lengthOfLists = self.getLengthOfLinkedList(head)
        
        if k > lengthOfLists:
            return head

        numberOfIterations = int(lengthOfLists / k)
        while head and numberOfIterations > 0:
            newStartNode, newEndNode = self.reverseLinkedList(head, previousNode, k-1)
            previousNode = newEndNode
            head = newStartNode
            numberOfIterations -= 1

        return self.finalStartNode
        

        

