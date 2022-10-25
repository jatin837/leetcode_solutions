class Solution {
public:
  int memo[1001][1001];
  int dp(string& s, string& t, int i, int j){
    if(j == -1)
      return 1;
    if(i == -1)
      return 0;
    if(memo[i][j] != -1)
      return memo[i][j];
    if(s[i] == t[j]) memo[i][j] = dp(s, t, i-1, j-1) + dp(s, t, i-1, j);
    else memo[i][j] = dp(s, t, i-1, j);
    return memo[i][j];
  }
  int numDistinct(string s, string t) {
    memset(memo, -1, sizeof(memo));
    return dp(s, t, s.size()-1, t.size()-1);
  }
};