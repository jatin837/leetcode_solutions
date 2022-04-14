class Solution {
public:
    int minDistance(string word1, string word2) {
      int r = word1.length();
      int c = word2.length();
      
      vector<vector<int>>dp(r+1, vector<int>(c+1, 0));
      
      for(int i=c; i>=0; i--)
        dp[r][c-i] = i;
      
      for(int i=r; i>=0; i--)
        dp[r-i][c] = i;
      
      for(int i=c-1; i>=0; i--){
        for(int j=r-1; j>=0; j--){
          if(word1[j] == word2[i]){
            dp[j][i] = dp[j+1][i+1];
          }else{
            dp[j][i] = 1+min(dp[j+1][i], min(dp[j][i+1], dp[j+1][i+1]));
          } 
        }
      }
      
//    for(auto r:dp){
//      for(auto c:r){
//        cout<<c<<' ';
//      }
//      cout<<'\n';
//    }
      return dp[0][0];
    }
};