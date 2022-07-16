class Solution{
public:
  const long int M= 1e9+7;
  int solve(int i, int j ,int k,int m,int n,vector<vector<vector<int>>>&dp){
      if(i<0||j<0||j>=n||i>=m)
        return 1;
      if(k==0)return 0;
      if(dp[i][j][k]!=-1)
        return dp[i][j][k];
      int up= solve(i-1,j,k-1,m,n,dp)%M;
      int down = solve(i+1,j,k-1,m,n,dp)%M;
      int right =  solve(i,j+1,k-1,m,n,dp)%M;
      int left= solve(i,j-1,k-1,m,n,dp)%M;
      return dp[i][j][k]=(up%M+down%M+left%M+right%M)%M;
  }
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
      return solve(startRow,startColumn,maxMove,m,n,dp);
  }
};
