class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr)
      return nullptr;
    ListNode *p1=head, *p2=head;
    int diff = 0;
    int size = 0;
    while(p1){
      p1 = p1->next;
      size++;
    }
    p1 = head;
    while(p2->next){
      p2 = p2->next;
      if(diff < k%size){
        diff++;
        continue;
      }
      p1 = p1->next;
    }
    p2->next = head;
    head = p1->next;
    p1->next = nullptr;
    return head;
  }
};