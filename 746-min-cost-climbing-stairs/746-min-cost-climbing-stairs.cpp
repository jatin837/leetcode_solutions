class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int c1 = 0;int c2 = 0;
      int n = cost.size();
      int temp = 0;
      for (int i=2; i<cost.size(); i++){
        temp = c2; 
        c2 = min(cost[i-2] + c1, cost[i-1] + c2);
        c1 = temp;
      }
      return min(c2+cost[n-1], c1+cost[n-2]);
    }
};