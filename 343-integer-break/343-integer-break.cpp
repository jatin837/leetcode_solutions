class Solution {
public:
    int integerBreak(int n) {
      vector<int>dp(n+1, 0);
      dp[1] = 0;
      dp[2] = 2;
      
      if(n <3)
        return 1;
      if(n==3)
        return 2;
      for(int i=3; i<n+1; i++){
        if(i==n)
          dp[i] = 0;
        else
          dp[i] = i;
        
        for(int j=1; j<i; j++){
          dp[i] = max(dp[i], dp[j]*dp[i-j]);
        }
      }
      for(auto d:dp)
        cout<<d<<' ';
      cout<<'\n';
      return dp[n];
    }
};