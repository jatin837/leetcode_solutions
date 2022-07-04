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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
      vector<vector<int>>matrix(m, vector<int>(n, -1)); 
      spiralMatrix(0, 0, m-1, n-1, matrix, head);
      return matrix;
    }
    void spiralMatrix(int x1, int y1, int x2, int y2, vector<vector<int>>& matrix, ListNode* head){
      if(head == nullptr)
        return;
      for(int y=y1; y<=y2; y++){
        matrix[x1][y] = head->val;
        if(head->next == nullptr)
          return;
        head = head->next;
      }
      for(int x=x1+1; x<=x2-1; x++){
        matrix[x][y2] = head->val;
        if(head->next == nullptr)
          return;
        head = head->next;
      }
      for(int y=y2; y>=y1; y--){
        matrix[x2][y] = head->val;
        if(head->next == nullptr)
          return;
        head = head->next;
      }
      for(int x=x2-1; x > x1; x--){
        matrix[x][y1] = head->val;
        if(head->next == nullptr)
          return;
        head = head->next;
      }
      spiralMatrix(x1+1, y1+1, x2-1, y2-1, matrix, head);
    }
};