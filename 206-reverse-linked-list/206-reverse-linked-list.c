/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
  if(head == NULL)
    return NULL;
  if(head->next == NULL)
    return head;
  struct ListNode *front = reverseList(head->next);
  struct ListNode *back = head->next;
  back->next = head;
  head->next = NULL;
  return front;
}