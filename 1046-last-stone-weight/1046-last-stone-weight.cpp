class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> pq;
      for(int i=0; i<stones.size(); i++)
        pq.push(stones[i]); 
      while(!pq.empty()){
        int top = pq.top();
        pq.pop();
        if(pq.empty())
          return top;
        if(pq.top() != top){
          int diff = top - pq.top();
          pq.pop();
          pq.push(diff);
          continue;
        }
        pq.pop();
      }
      return 0;
    }
};