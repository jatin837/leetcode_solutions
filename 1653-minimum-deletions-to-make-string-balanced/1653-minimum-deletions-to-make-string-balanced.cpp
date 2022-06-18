class Solution {
public:
    int minimumDeletions(string s) {
      int len = s.length();
      vector<int>dp(len+1);
      int bcnt = 0;
      if(s[0] == 'b')
        bcnt++;
      for(int i=1; i<len; i++){
        if(s[i] == 'a'){
          // either keep this a or remove this a
          dp[i] = min(dp[i-1] + 1, bcnt);
        }else{
          bcnt++;
          dp[i] = dp[i-1];
        }
      }
      return dp[len-1];
    }
};