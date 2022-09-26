# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
      if(head == None):
        return None
      if(head.next == None):
        return head
      back, front = head.next, self.reverseList(head.next)
      back.next = head
      head.next = None
      return front