class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
      int ret = 0;
      int i = 0;
      while(i < colors.size()){
        int sum = neededTime[i];
        int mx = neededTime[i];
        while(i+1 < colors.size() && colors[i] == colors[i+1]){
          sum += neededTime[i+1];
          mx = max(mx, neededTime[i+1]);
          i++;
        }
        ret += sum - mx;
        i++;
      }
      return ret;
    }
};