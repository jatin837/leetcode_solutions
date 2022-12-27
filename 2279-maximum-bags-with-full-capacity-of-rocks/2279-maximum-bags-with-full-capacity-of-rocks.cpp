class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extra) {
      priority_queue<int,vector<int>,greater<int>>left;
      for(int i=0; i<rocks.size(); i++)
        left.push(capacity[i]-rocks[i]);
      int ret = 0;
      while(left.size() && extra > 0){
        if(left.top() > extra){
          return ret;
        }
        if(left.top() <= extra){
          extra -= left.top();
          left.pop();
          ret++;
        }
      }
      return ret;
    }
};