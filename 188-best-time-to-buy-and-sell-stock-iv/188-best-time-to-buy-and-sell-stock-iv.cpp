#define vvv vector<vector<vector<int>>>
class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
      vector<vector<int>>dp(K+1, vector<int>(prices.size(), 0));
      int ans = 0;
      for(int k=1; k<=K; k++){
        for(int i=1; i<prices.size(); i++){
          dp[k][i] = dp[k][i-1];
          for(int j=i-1; j>=0; j--){
            if(prices[i] > prices[j])
              if(j!=0)
                dp[k][i] = max(dp[k-1][j-1]+prices[i]-prices[j], dp[k][i]);
              else
                dp[k][i] = max(prices[i]-prices[j], dp[k][i]);
          } 
          ans = max(dp[k][i], ans);
        }
      }
      return ans;
    }
};