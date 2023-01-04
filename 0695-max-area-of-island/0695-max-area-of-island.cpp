class Solution {
public:
    int dfs(int r, int c, int currArea, vector<vector<int>>&grid){
      if(r<0 or r>=grid.size() or c<0 or c>=grid[0].size() or !grid[r][c])
        return 0;
      grid[r][c] = 0;
      currArea +=  dfs(r-1, c, 0, grid);
      currArea +=  dfs(r+1, c, 0, grid);
      currArea +=  dfs(r, c-1, 0, grid);
      currArea +=  dfs(r, c+1, 0, grid);
      return currArea+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int ans = 0;
      for(int i=0; i<grid.size(); i++)
        for(int j=0; j<grid[0].size(); j++)
          if(grid[i][j])
            ans = max(ans, dfs(i, j, 0, grid));
      return ans;
    }
};