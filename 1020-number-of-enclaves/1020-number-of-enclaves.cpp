class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& g){
      if(i<0 || j<0 || i==g.size() || j==g[0].size() || g[i][j]==0)
        return 0;
      g[i][j] = 0;
      int ans = 1;
      ans += dfs(i-1, j, g);
      ans += dfs(i+1, j, g);
      ans += dfs(i, j-1, g);
      ans += dfs(i, j+1, g);
      return ans;
    }
    int numEnclaves(vector<vector<int>>& g) {
      for(int j=0; j<g[0].size(); j++){
        dfs(0, j, g);
        dfs(g.size()-1, j, g);
      }
      for(int i=0; i<g.size(); i++){
        dfs(i, 0, g);
        dfs(i, g[0].size()-1, g);
      }
      int cnt = 0;
      for(int i=0; i<g.size(); i++)
        for(int j=0; j<g[0].size(); j++)
          cnt+=dfs(i, j, g);
      return cnt;
    }
};