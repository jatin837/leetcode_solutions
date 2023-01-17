class Solution {
public:
  void dfs(int node, vector<vector<int>>&G, vector<bool>&visited){
    visited[node] = true;
    for(int c:G[node])
      dfs(c, G, visited);
  }
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int>in(n, 0);
    for(auto e:edges)
      in[e[1]]++;
    vector<int>ret;
    for(int i=0; i<n; i++)
      if(in[i] == 0)
        ret.push_back(i);
    return ret;
  }
};