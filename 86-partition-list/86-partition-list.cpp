class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode *A = new ListNode(-1), *B = new ListNode(-1);
      ListNode *pA =A, *pB = B;
      while(head){
        if(head->val < x){
          pA->next = head;
          pA = head;
        }else{
          pB->next = head;
          pB = head;
        }
        head = head->next;
      }
      pB->next = nullptr;
      pA->next = B->next;
      return A->next;
    }
};