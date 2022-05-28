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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;
    while (curr != nullptr && count != k) { // find the k+1 node
        curr = curr->next;
        count++;
    }
    if (count == k) { // if k+1 node is found
        curr = reverseKGroup(curr, k);
        while (count-- > 0) {
            ListNode *tmp = head->next;
            head->next = curr;
            curr = head;
            head = tmp;
        }
        head = curr;
    }
    return head;
  }
};