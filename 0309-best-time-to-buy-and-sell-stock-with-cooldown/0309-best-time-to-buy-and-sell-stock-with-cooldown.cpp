class Solution {
private:
  int dp[5001][2];
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      memset(dp, 0, sizeof(dp));
      for(int i=n-1; i>=0; i--){
        dp[i][0] = max(dp[i+2][1] + prices[i], dp[i+1][0]);
        dp[i][1] = max(dp[i+1][0] - prices[i], dp[i+1][1]);
      }
      return dp[0][1];
    }
};