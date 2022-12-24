class Solution {
public:
    int numTilings(int n) {
      long long dp[1001][2];
      memset(dp, 0, sizeof(dp));
      dp[1][0] = 1;
      dp[1][1] = 0;
      dp[2][0] = 2;
      dp[2][1] = 1;
      int mod = 1e9+7;
      for(int i=3; i<=n; i++){
        dp[i][0] = (dp[i-1][0]%mod + dp[i-2][0]%mod + 2*dp[i-1][1]%mod)%mod;
        dp[i][1] = (dp[i-1][1]%mod + dp[i-2][0]%mod)%mod;
      }
      return dp[n][0]%mod;
    }
};