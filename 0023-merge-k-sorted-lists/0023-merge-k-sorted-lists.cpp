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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode* head = new ListNode(0);
      ListNode* curr = head;
      int len = lists.size();
 
      if(len == 0)
        return nullptr;
      
      
      for(int i=0; i<len; i++){
        if(lists[i] == nullptr)
          lists[i] = new ListNode(INT_MAX);
      }
      
      pair<int, ListNode*> best = {0, lists[0]};
      
      bool done = false;
      while(not done){
        done = true;
        for(int i=0; i<len; i++){
          if(lists[i] == nullptr)
            lists[i] = new ListNode(INT_MAX);
          if(lists[i]->val < best.second->val)
            best = {i, lists[i]};
          done = done & (lists[i]->val == INT_MAX);
        }
        if(done)
          break;
        curr->next = new ListNode(best.second->val);
        curr = curr->next;
        if(lists[best.first]->next)
          lists[best.first] = lists[best.first]->next;
        else
          lists[best.first] = new ListNode(INT_MAX);
        best = {best.first, lists[best.first]};       
      }
      return head->next;
    }
};