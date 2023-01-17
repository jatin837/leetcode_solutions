class Solution {
public:
  int dp[2][100001];
  int f(int pos, char prev, string& s){
    if(pos == s.length())
      return 0;
    char curr = s[pos];
    if(dp[prev-'0'][pos] != -1)
      return dp[prev-'0'][pos];
    if(curr == '0' && prev == '0')
      dp[prev-'0'][pos] =  min(
        f(pos+1, '0', s), // no flip
        1+f(pos+1, '1', s) // flip
      );
    else if(curr == '0' && prev == '1')
      dp[prev-'0'][pos] = 1+f(pos+1, '1', s);
    else if(curr == '1' && prev == '0')
      dp[prev-'0'][pos] = min(
        f(pos+1, '1', s), // no flip
        1+f(pos+1, '0', s) // flip
      );
    else dp[prev-'0'][pos] = f(pos+1, '1', s);
    return dp[prev-'0'][pos];
  }
  int minFlipsMonoIncr(string s) {
    memset(dp, -1, sizeof(dp));
    return f(0, '0', s);
  }
};