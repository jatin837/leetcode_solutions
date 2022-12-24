class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode *p = head;
      unordered_map<ListNode*, bool>st;
      while(p){
        if(st[p])
          return p;
        st[p] = true;
        p = p->next;
      }
      return nullptr;
    }
};