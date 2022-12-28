class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
      priority_queue<int>pq(piles.begin(), piles.end());
      while(k--){
        int top = pq.top()+1;
        if(top == 1)
          return 0;
        pq.pop();
        pq.push(top/2);
      }
      int ret = 0;
      while(pq.size()){
        ret += pq.top();
        pq.pop();
      }
      return ret;
    }
};