class Solution {
public:
  int color[101];
  bool dfs(vector<vector<int>>&G, int node, int col){
    if(color[node] == -1){
      color[node] = col;
      for(int c:G[node])
        if(!dfs(G, c, !col)) return false;
        else dfs(G, c, !col);
    }
    return color[node] == col;
  }
  bool isBipartite(vector<vector<int>>& G) {
    memset(color, -1, sizeof(color));
    for(int i=0; i<G.size(); i++)
      if((color[i] == -1) && !dfs(G, i, 1))
        return false;
    return true;
  }
};