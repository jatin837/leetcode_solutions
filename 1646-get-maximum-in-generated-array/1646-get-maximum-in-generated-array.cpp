class Solution {
public:
    int getMaximumGenerated(int n) {
      if(n == 0)
        return 0;
      if(n == 1)
        return 1;
      vector<int>dp(n+1);
      dp[0] = 0;
      dp[1] = 1;
      int ans = 1;
      for(int i=2; i<=n; i++){
        dp[i] = dp[i>>1] + int(i&1)*dp[(i>>1) + 1];
        ans = max(ans, dp[i]);
      }
      return ans;
    }
};