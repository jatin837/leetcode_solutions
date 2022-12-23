class Solution {
public:
    bool isSubsequence(string s, string t) {
      int r = t.length();
      int c = s.length();
      
      if(c==0)
        return true;
      if(r==0 and c != 0)
        return false;
      if(r==0 and c==0)
        return true;
      
      vector<vector<int>>dp(r, vector<int>(c, false));
      
      if(t[r-1] == s[c-1])
        dp[r-1][c-1] = true;
      
      for(int i=r-2; i>=0; i--){
        if(t[i] == s[c-1])
          dp[i][c-1] = true;
        else
          dp[i][c-1] = dp[i+1][c-1];
      }
      
  
      for(int i=0; i<c-1; i++)
        dp[r-1][i] = false;
      
      for(int i=c-2; i>= 0; i--){
        for(int j=r-2; j>=0; j--){
          if(t[j] == s[i])
            dp[j][i] = dp[j+1][i+1];
          else
            dp[j][i] = dp[j+1][i];
        }
      }
      
      for(auto r:dp){
        for(auto c:r)
          cout<<c<<' ';
        cout<<'\n';
      }
      return dp[0][0];
   }
};