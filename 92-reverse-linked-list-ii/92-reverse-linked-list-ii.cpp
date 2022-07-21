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
   ListNode* reverseBetween(ListNode* head, int left, int right) {
     if(left == right)
       return head;
     ListNode* dummy = new ListNode(-1000, head);
     ListNode* a = dummy;
     ListNode* b;
     ListNode* start;
     int cnt = 0;
     while(a->next and cnt++ != left){
       start = a;
       a=a->next;
       b=a->next;
     }
     while(a and b and cnt++ != right+1){
       ListNode* tmp = b->next;
       b->next = a;
       a = b;
       b = tmp;
     }
     start->next->next = b;
     start->next = a;
     return dummy->next;
    }
};