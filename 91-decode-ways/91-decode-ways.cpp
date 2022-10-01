class Solution {
public:
  int numDecodings(string s) {
    vector<int>memo(s.length()+1, -1);
    return dp(s, 0, memo);
  }
  int dp(string &s, int pos, vector<int>&memo){
    if(pos == s.length())
      return 1;
    if(s[pos] == '0')
      return 0;
    if(memo[pos] == -1){
      int ret = dp(s, pos+1, memo);
      if(pos+1<s.length()){
        if((s[pos] == '1') || (s[pos] == '2' && s[pos+1] <= '6'))
          ret += dp(s, pos+2, memo);
      }
      memo[pos] = ret;
    }

    return memo[pos];
  }
};