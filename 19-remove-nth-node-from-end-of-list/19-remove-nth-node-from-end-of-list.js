/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
  let newHead = new ListNode(-1, head);
  let first = newHead, second = newHead;
  let gap = 0;
  while(second){
    if(gap != n+1){
      gap++;
      second = second.next;
      continue;
    }
    [first, second] = [first.next, second.next];
  }
  first.next = first.next.next;
  return newHead.next;
};