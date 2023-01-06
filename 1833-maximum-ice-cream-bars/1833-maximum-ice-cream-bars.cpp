class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      sort(begin(costs), end(costs));
      int ret=0;
      int i=0;
      while(i < costs.size() && coins > 0){
        coins -= costs[i];
        if(coins < 0)
          break;
        ret++;
        i++;
      }
      return ret;
    }
};