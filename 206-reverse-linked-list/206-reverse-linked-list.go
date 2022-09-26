/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
  if(head == nil){
    return nil;
  }
  if(head.Next == nil){
    return head;
  }
  var back *ListNode = head.Next;
  var front *ListNode = reverseList(back);
  back.Next = head;
  head.Next = nil;
  return front;
}