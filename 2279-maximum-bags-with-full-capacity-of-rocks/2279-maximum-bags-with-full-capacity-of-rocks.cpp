class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extra) {
      priority_queue<int,vector<int>,greater<int>>left;
      for(int i=0; i<rocks.size(); i++)
        capacity[i]-=rocks[i];
      sort(capacity.begin(), capacity.end());
      int ret = 0;
      for(int n:capacity){
        extra -= n;
        if(extra < 0)
          return ret;
        ret++;
      }
      return ret;
    }
};