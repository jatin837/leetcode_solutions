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
    bool isPalindrome(ListNode* head) {
      int len = 0;
      stack<int>st;
      ListNode* curr = head;
      int i=0;
      while(curr){
        len++;
        curr = curr->next;
      }
      curr = head;
      while(i<(len>>1)){
        i++;
        st.push(curr->val);
        curr = curr->next;
      }
      if(len&1)
        curr = curr->next;
      
      while(!st.empty()){
        if(curr->val != st.top())
          return false;
        curr = curr->next;
        st.pop();
      }
      return true;
    }
};