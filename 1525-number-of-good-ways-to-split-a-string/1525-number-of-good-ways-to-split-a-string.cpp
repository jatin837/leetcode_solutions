class Solution {
public:
    int numSplits(string s) {
      unordered_set<char>right, left;
      int cnt = 0;
      vector<int>dp(s.length()+1, 0);
      for(int i=1; i<=s.length(); i++){
        right.insert(s[s.length()-i]);
        dp[s.length()-i] = right.size();
      }
      for(int i=0; i<s.length()-1; i++){
        left.insert(s[i]);
        //cout<<left.size()<<' '<<dp[i+1]<<'\n';
        if(left.size() == dp[i+1])
          cnt++;
      }
      return cnt;
    }
};