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
      vector<int>a, b;
      while(head){
        if(head->val>=x)
          b.push_back(head->val);
        else
          a.push_back(head->val);
        head = head->next;
      }
      ListNode* ans = new ListNode(0);
      ListNode* prev = ans;
      for(int i=0; i<a.size(); i++){
        ListNode* curr = new ListNode(a[i]);
        prev->next = curr;
        prev = curr;
      }
      for(int i=0; i<b.size(); i++){
        ListNode* curr = new ListNode(b[i]);
        prev->next = curr;
        prev = curr;
      }
      return ans->next;
    }
};