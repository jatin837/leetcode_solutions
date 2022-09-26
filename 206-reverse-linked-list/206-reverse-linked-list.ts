/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseList(head: ListNode | null): ListNode | null {
  if(head == null)
    return null;
  if(head.next == null)
    return head;
  let back: ListNode = head.next;
  let front: ListNode = reverseList(back);
  back.next = head;
  head.next = null;
  return front;
};