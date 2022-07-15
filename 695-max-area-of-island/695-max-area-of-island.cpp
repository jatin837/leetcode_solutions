class Solution {
public:
    int dfs(int r, int c, int currArea, vector<vector<int>>&grid){
      if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c] == 0)
        return 0;
      grid[r][c] = 0;
      currArea = 1 + dfs(r-1, c, 0, grid);
      currArea +=  dfs(r+1, c, 0, grid);
      currArea +=  dfs(r, c-1, 0, grid);
      currArea +=  dfs(r, c+1, 0, grid);
      return currArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int rl = grid.size();
      int cl = grid[0].size();
      int ans = 0;
      for(int i=0; i<rl; i++)
        for(int j=0; j<cl; j++)
          if(grid[i][j] == 1)
            ans = max(ans, dfs(i, j, 0, grid));
      return ans;
    }
};