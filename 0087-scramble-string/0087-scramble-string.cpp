class Solution {
public:
  int memo[31][31][31];
  bool isScramble(string s1, string s2) {
    memset(memo, -1, sizeof(memo));
    return dp(s1, s2, 0, 0, s1.size());
  }
  bool dp(string& s1, string& s2, int i, int j, int l){
    if(l == 0 || memo[i][j][l] == 0)
      return false;
    if(memo[i][j][l] == -1){
      if(s1.substr(i, l) == s2.substr(j, l))
        memo[i][j][l] = 1;
    
      else
        for(int k=1; k<=l-1; k++)
          if((dp(s1, s2, i, j, k) && dp(s1, s2, i+k, j+k, l-k)) || (dp(s1, s2, i, j+l-k, k) && dp(s1, s2, i+k, j, l-k))){
            memo[i][j][l] = 1;break;
          }
    
      if(memo[i][j][l] != 1)
        memo[i][j][l] = 0;     
    }
    return memo[i][j][l] == 1;
  }
};