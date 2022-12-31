class Solution {
public:
    int empty = 1;
    int ret = 0;
    void dfs(int x, int y, vector<vector<int>>&G, int cnt){
      if(x < 0 || y < 0 || x == G.size() || y == G[0].size() || G[x][y] == -1)
        return;
      if(G[x][y] == 2){
        if(cnt == empty){
          ret++;
          return;
        }
        return;
      }
      G[x][y] = -1;
      dfs(x+1, y, G, cnt+1);
      dfs(x-1, y, G, cnt+1);
      dfs(x, y+1, G, cnt+1);
      dfs(x, y-1, G, cnt+1);
      G[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
      int x, y;
      for(int i=0; i<grid.size(); i++)
        for(int j=0; j<grid[0].size(); j++)
          if(grid[i][j] == 1){
            x = i, y = j;
          }else if(grid[i][j] == 0)
            empty++;
      dfs(x, y, grid, 0);
      return ret;
    }
};