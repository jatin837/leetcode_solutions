class Solution {
public:
    int numSplits(string s) {
      int right=0, left=0;
      int cnt = 0;
      vector<int>dp(s.length()+1, 0);
      for(int i=1; i<=s.length(); i++){
        right |= 1<<(s[s.length()-i] - 'a');
        dp[s.length()-i] = __builtin_popcount(right);
      }
      for(int i=0; i<s.length()-1; i++){
        left |= 1<<(s[i] - 'a');
        if(__builtin_popcount(left) == dp[i+1])
          cnt++;
      }
      return cnt;
    }
};