class Solution {
public:
  vector<vector<int>>ret;
  void dfs(int pos, vector<vector<int>>&G, vector<int>tmp){
    tmp.push_back(pos);
    if(pos == G.size()-1){
      ret.push_back(tmp);
      return;
    }
    for(int n:G[pos])
      dfs(n, G, tmp);
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    dfs(0, graph, {});
    return ret;
  }
};