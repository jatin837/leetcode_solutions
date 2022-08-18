class Solution {
public:
  void dfs(vector<vector<int>>& G, unordered_set<int>&visited, int node){
    visited.insert(node);
    for(int n:G[node])
      if(visited.count(n) == 0)
        dfs(G, visited, n);
    
  }
  int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n-1)
      return -1;
    unordered_set<int>visited;
    vector<vector<int>> G(n);
    for (auto conn:connections)
      G[conn[0]].push_back(conn[1]), G[conn[1]].push_back(conn[0]);
    int cnt = 0;
    for(int i=0; i<n; i++){
      if(visited.count(i))
        continue;
      cnt++;
      dfs(G, visited, i);
    }
    return cnt-1;
  }
};