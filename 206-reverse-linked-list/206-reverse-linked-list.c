/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
  struct ListNode *curr = head, *prev = NULL; 
  while(curr){
    struct ListNode *tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }
  return prev;
}