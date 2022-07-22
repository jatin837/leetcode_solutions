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
    ListNode* partition(ListNode* head, int x) {
      
      ListNode *A = new ListNode(-1), *B = new ListNode(-1), *pA = A, *pB = B;
      while(head){
        ListNode* curr = new ListNode(head->val);
        if(curr->val >= x){
          pA->next = curr;
          pA = curr;
        }else{
          pB->next = curr;
          pB = curr;
        }
        head = head->next;
      }
////  ListNode* ans = new ListNode(0);
////  ListNode* prev = ans;
////  for(int i=0; i<a.size(); i++){
////    ListNode* curr = new ListNode(a[i]);
////    prev->next = curr;
////    prev = curr;
////  }
////  for(int i=0; i<b.size(); i++){
////    ListNode* curr = new ListNode(b[i]);
////    prev->next = curr;
////    prev = curr;
////  }
      pB->next = A->next;
      return B->next;
    }
};