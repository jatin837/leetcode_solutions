class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if(head == nullptr)
        return nullptr;
      if(head->next==nullptr)
        return head;
      ListNode* prev = head;
      ListNode* curr = prev->next;
      ListNode* next = curr->next;
      
      
      curr->next = prev;
      prev->next = next;
      
      head = curr;
      head->next->next = swapPairs(head->next->next);
      
      return head; 
    }
};