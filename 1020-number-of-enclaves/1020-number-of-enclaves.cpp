class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& g){
      if(i<0 || j<0 || i==g.size() || j==g[0].size() || g[i][j]==0)
        return 0;
      int ans = 0;
      g[i][j] = 0;
      ans += dfs(i-1, j, g);
      ans += dfs(i+1, j, g);
      ans += dfs(i, j-1, g);
      ans += dfs(i, j+1, g);
      return 1+ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
      for(int j=0; j<grid[0].size(); j++){
        dfs(0, j, grid);
        dfs(grid.size()-1, j, grid);
      }
      for(int i=0; i<grid.size(); i++){
        dfs(i, 0, grid);
        dfs(i, grid[0].size()-1, grid);
      }
      int cnt = 0;
      for(int i=0; i<grid.size(); i++)
        for(int j=0; j<grid[0].size(); j++)
          if(grid[i][j])
            cnt+=dfs(i, j, grid);
      return cnt;
    }
};