class Solution {
public:
    int numDecodings(string s) {
      
      if (s[0] == '0')
        return 0;
      
      int n = s.length();
      vector<int> dp(n, 0);
      
      dp[0] = 1;
      
      if (n == 1)
        return dp[0];
      
      
      if (s[0] == '1'){
        if (s[1] == '0')
          dp[1] = 1;
        else
          dp[1] = 2;
      }
       
      if (s[0] == '2'){
        if (s[1] >= '1' and s[1] <= '6')
          dp[1] = 2;
        else if (s[1] == '0')
          dp[1] = 1;
        else
          dp[1] = 1;
      }
      
      if (s[0] >= '3'){
        if (s[1] == '0')
          return 0;
        else
          dp[1] = 1;
      }
      for(int i=2; i<n; i++){
        if (s[i] == '0'){
          if (s[i-1] == '1' or s[i-1] == '2')
            dp[i] = dp[i-2];
          else
            return 0;
        }
        if (s[i] >= '1' and s[i] <= '6'){
          if (s[i-1] == '2' or s[i-1] == '1')
            dp[i] = dp[i-2] + dp[i-1];
          else
            dp[i] = dp[i-1];
        }
        if (s[i] >= '7'){
          if (s[i-1] == '1')
            dp[i] = dp[i-2] + dp[i-1];
          else if (s[i-1] == '0')
            dp[i] = dp[i-2];
          else
            dp[i] = dp[i-1];
        }
      }
      return dp[n-1];
    }
};