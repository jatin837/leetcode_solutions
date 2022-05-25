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
      ListNode* curr = head;
      int len = 0;
      if(head->next==nullptr)
        return nullptr;
      while(curr){
        len++;
        curr = curr->next;
      }
        
      curr = head;
      
      n = len - n;
      if(n == 0)
        return head->next;
      while(--n>0)
        curr = curr->next; 
      
      curr->next = curr->next->next;
      
      return head;
    }
};