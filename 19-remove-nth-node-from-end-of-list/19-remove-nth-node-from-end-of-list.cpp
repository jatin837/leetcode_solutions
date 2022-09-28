/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* newHead = new ListNode(-1, head);
      ListNode *first = newHead, *second = newHead;
      int gap = 0;
      while(second){
        if(gap <= n){
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
};