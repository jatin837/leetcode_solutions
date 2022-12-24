/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode *fast = head, *slow = head;
      while(fast != nullptr and fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
          slow = head;
          while(fast != slow){
            fast = fast->next;
            slow = slow->next;
          }
          return slow;
        }
      }
      return nullptr;
    }
};