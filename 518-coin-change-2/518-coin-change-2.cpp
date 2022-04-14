class Solution {
public:
    int change(int amt, vector<int>& coins) {
      int n = coins.size();
      vector<vector<int>>dp(amt+1, vector<int>(n+1, 0));
      sort(coins.begin(), coins.end());
      
      for(int i=0; i<n+1; i++)
        dp[0][i] = 1;
      
      
      for(int j=1; j<n+1; j++){
        for(int i=1; i<amt+1; i++){
          if(coins[j-1] > i)
            dp[i][j] = dp[i][j-1];
          else
            dp[i][j] = dp[i-coins[j-1]][j] + dp[i][j-1];
        }
      }
      
//    for(auto r:dp){
//      for(auto c:r){
//        cout<<c<<' ';
//      }
//      cout<<'\n';
//    }
//    
      return dp[amt][n]; 
    }
};