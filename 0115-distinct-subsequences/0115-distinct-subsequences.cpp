class Solution {
public:
  unsigned memo[1001][1001];
  int numDistinct(string s, string t) {
    memset(memo, 0, sizeof(memo));
    for(int i=0; i<=t.size(); i++)
      memo[0][i] = 0;
    for(int i=0; i<=s.size(); i++)
      memo[i][0] = 1;
    for(int j=1; j<=t.size(); j++)
      for(int i=1; i<=s.size(); i++)
        if(s[i-1] == t[j-1])
          memo[i][j] = memo[i-1][j] + memo[i-1][j-1];
        else
          memo[i][j] = memo[i-1][j];
    return memo[s.size()][t.size()];
  }
};