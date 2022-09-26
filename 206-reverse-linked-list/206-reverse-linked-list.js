/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
  if(head == null)
    return null;
  if(head.next == null)
    return head;
  let back = head.next;
  let front = reverseList(back);
  back.next = head;
  head.next = null;
  return front;
};