class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
      int r = grid.size();
      int c = grid[0].size();
      vector<vector<long long>>dp(r, vector<long long>(c, INT_MAX));
      for(int i=0; i<grid[0].size(); i++){
        dp[0][i] = grid[0][i];
      }
      for(int rr = 1; rr < r; rr++){
        for(int cc = 0; cc < c; cc++){
          for(int k = 0; k<c; k++){
            dp[rr][cc] = min(dp[rr][cc], grid[rr][cc] + moveCost[grid[rr-1][k]][cc] + dp[rr-1][k]);
          }
        }
      }
      return *min_element(dp[r-1].begin(), dp[r-1].end());
    }
};