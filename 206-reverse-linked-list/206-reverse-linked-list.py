class Solution:
  def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    prev, curr = None, head;
    while curr:
      tmp = curr.next
      curr.next = prev
      prev = curr
      curr = tmp
    return prev