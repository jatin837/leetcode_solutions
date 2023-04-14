class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int n = s.length();
      vector<vector<int>>dp(n, vector<int>(n, 0));
      for(int i=0; i<n; i++){
        dp[i][i] = 1;
      }
      int ans = 1;
      for(int i=1; i<n; i++){
        if (s[i] == s[i-1])
          dp[i][i-1] = 2;
        else
          dp[i][i-1] = 1;
        ans = max(ans, dp[i][i-1]);
      }
      for(int i=2; i<n; i++){
        for(int j=i-2; j>=0; j--){
          if(s[i] == s[j])
            dp[i][j] = dp[i-1][j+1] + 2; 
          else
            dp[i][j] = max(dp[i][j+1], dp[i-1][j]); 
          ans = max(ans, dp[i][j]);
        }
      }
//    for (auto r:dp){
//      for(auto c:r){
//        cout<<c<<' ';
//      }
//      cout<<'\n';
//    }
      return ans;
    }
};