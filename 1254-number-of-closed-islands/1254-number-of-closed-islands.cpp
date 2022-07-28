class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&grid){
      if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==1)
        return;
      grid[i][j] = 1;
      dfs(i-1, j, grid);
      dfs(i+1, j, grid);
      dfs(i, j-1, grid);
      dfs(i, j+1, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
      int cnt = 0;
      for(int i=0; i<grid.size(); i++){
        dfs(i, 0, grid);
        dfs(i, grid[0].size()-1, grid);
      }
      for(int i=0; i<grid[0].size(); i++){
        dfs(0, i, grid);
        dfs(grid.size()-1, i, grid);
      }
      for(int i=1; i<grid.size(); i++){
        for(int j=1; j<grid[0].size(); j++){
          if(grid[i][j])
            continue;
          cnt += 1;
          dfs(i, j, grid);
        }
      }
      return cnt;
    }
};