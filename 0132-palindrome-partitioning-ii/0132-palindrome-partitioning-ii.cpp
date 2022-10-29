class Solution {
public:
  int minCut(string s) {
    bool isPalindrome[2001][2001];
    vector<int>dp(2002, 2002);
    memset(isPalindrome, false, sizeof(isPalindrome));
    for(int i=0; i<s.length(); i++){
      isPalindrome[i][i] = true;
      if(i+1 < s.length() && s[i] == s[i+1])
        isPalindrome[i][i+1] = true;
    }
    for(int r = s.length()-3; r>=0; r--)
      for(int c = r+2; c<s.length(); c++)
        isPalindrome[r][c] = (s[r] == s[c])&&(isPalindrome[r+1][c-1]);
    
/// for(int i=0; i<s.length(); i++)
///   cout<<dp[i]<<' ';
/// cout<<'\n';
    dp[s.length()-1] = 0;
    for(int i=s.length()-2; i>=0; i--){
      if(isPalindrome[i][s.length()-1])
        dp[i] = 0;
      else
        for(int k=i; k<s.length()-1; k++)
          if(isPalindrome[i][k])
            dp[i] = min(dp[i], dp[k+1]+1);
    }
/// for(int i=0; i<s.length(); i++)
///   cout<<dp[i]<<' ';
/// cout<<'\n';
    return dp[0];
  }
};