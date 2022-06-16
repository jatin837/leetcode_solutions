using namespace std;

class Solution {
public:
  string solve(string s){
    
    int dp[1002][1002];
    for(int i=0; i<s.length(); i++)
      dp[i][i] = 1;
    
    for(int i=0; i<s.length()-1; i++){
      if (s[i] == s[i+1]){
        dp[i][i+1] = 1;
        dp[i+1][i] = 1;
      }
   }
   for (int i=2; i<s.length(); i++)
     for (int j=i-2; j>=0; j--)
       if ((s[i] == s[j]) and (dp[i-1][j+1] == 1))
         dp[i][j] = 1;
    
   int ia=0; int ja = 0; 
    for(int i=0; i<s.length(); i++)
      for(int j=0; j<s.length(); j++)
        if (dp[i][j])
          if (abs(i-j) > abs(ia-ja)){ ia=i; ja=j; }

    string ans = string(s.begin() + min(ia, ja), s.begin() + max(ia, ja)+1);

    for(int i=0; i<s.length(); i++)
      for(int j=0; j<s.length(); j++)
        dp[i][j] = 0;
    return ans;
  }
  string longestPalindrome(string s) {
    return solve(s);
  }
};