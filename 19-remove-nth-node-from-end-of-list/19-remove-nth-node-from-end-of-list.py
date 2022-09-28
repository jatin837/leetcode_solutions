# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    newHead = ListNode(-1, head)
    first, second = newHead, newHead
    gap = 0
    while(second):
      if(gap != n+1):
        gap+=1
        second = second.next
        continue
      first = first.next
      second = second.next
    first.next = first.next.next
    return newHead.next