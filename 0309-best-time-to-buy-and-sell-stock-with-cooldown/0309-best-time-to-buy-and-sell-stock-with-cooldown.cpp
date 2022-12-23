class Solution {
private:
  int dp[5001][2];
  int f(int day, bool buy, vector<int>&prices){
    if(day >= prices.size())
      return 0;
    if(dp[day][buy] != -1)
      return dp[day][buy];
    if(buy) dp[day][buy] = max(-prices[day] + f(day+1, false, prices), f(day+1, true, prices));
    else dp[day][buy] = max(prices[day]+f(day+2, true, prices), f(day+1, false, prices));
    return dp[day][buy];
  }
public:
    int maxProfit(vector<int>& prices) {
      memset(dp, -1, sizeof(dp));
      return f(0, true, prices);
    }
};