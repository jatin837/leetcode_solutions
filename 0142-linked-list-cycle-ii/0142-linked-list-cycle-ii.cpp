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
      ListNode *p = head;
      unordered_set<ListNode*>st;
      while(p){
        if(st.count(p))
          return p;
        st.insert(p);
        p = p->next;
      }
      return nullptr;
    }
};