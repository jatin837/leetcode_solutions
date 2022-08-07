class Solution {
public:
    int countVowelPermutation(int n) {
      long long dp[20000][5] = {{1, 1, 1, 1, 1}}; 
      long long mod = 1e9+7;
      cout<<dp[0][3];
      int ans;
      for(int i=1; i<n; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4])%mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
        dp[i][3] = (dp[i-1][2])%mod;
        dp[i][4] = (dp[i-1][3] + dp[i-1][2])%mod;
      }
      for(auto num:dp[n-1])
        ans = (ans + num)%mod;
      return ans;
    }
};