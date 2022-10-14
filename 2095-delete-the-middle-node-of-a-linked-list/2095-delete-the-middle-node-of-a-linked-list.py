# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
    slow = head
    fast = head.next
    while(slow and fast and fast.next and fast.next.next):
      slow = slow.next
      fast = fast.next.next
    if slow.next == None:
      return None
    slow.next = slow.next.next
    return head