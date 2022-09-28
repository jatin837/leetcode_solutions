/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
  struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
  newHead->val = -1;
  newHead->next = head;
  int gap = 0;
  struct ListNode *first = newHead, *second = newHead;
  while(second){
    if(gap != n+1){
      gap++;
      second = second->next;
      continue;
    }
    first = first->next;
    second = second->next;
  }
  first->next = first->next->next;
  return newHead->next;
}