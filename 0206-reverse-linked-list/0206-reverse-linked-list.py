class Solution:
  def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if(head == None):
      return None
    if(head.next == None):
      return head
    ret = self.reverseList(head.next)
    head.next.next = head
    head.next = None
    return ret
    