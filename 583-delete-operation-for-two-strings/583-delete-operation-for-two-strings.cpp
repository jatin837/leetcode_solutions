// It's just Longest Common Subsequence problem
// I have provided a link to youtube video if you'd like to  understand the problem
// once we have the length of longest common subsequece, we can just subtract it from length of both words and add to obtain final answer
class Solution {
public:
    int minDistance(string word1, string word2) {
      int r = word1.length();
      int c = word2.length();
      
      vector<vector<int>>dp(r+1, vector<int>(c+1,0));
      
      int maxLen = 0;
      
      for(int i=c-1; i>=0; i--){
        for(int j=r-1; j>=0; j--){
          if(word1[j] == word2[i])
            dp[j][i] = dp[j+1][i+1] + 1;
          else
            dp[j][i] = max(dp[j][i+1], dp[j+1][i]);
          maxLen = max(maxLen, dp[j][i]);
        }
      }
      int ans = 0;
      ans += r-maxLen;
      ans += c-maxLen;
      return ans;
    }
};