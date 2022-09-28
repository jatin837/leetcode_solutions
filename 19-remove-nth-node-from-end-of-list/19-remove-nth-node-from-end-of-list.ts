function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
  var newHead : ListNode = new ListNode(-1, head);
  var gap: number = 0;
  var first: ListNode = newHead;
  var second: ListNode = newHead;
  while(second){
    if(gap != n+1){
      gap++;
      second = second.next;
      continue;
    }
    first = first.next;
    second = second.next;
  }
  first.next = first.next.next;
  return newHead.next;
};