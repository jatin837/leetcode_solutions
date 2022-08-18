class Solution {
public:
  void dfs(int node, vector<vector<int>>& G, unordered_set<int>& visited){
    visited.insert(node);
    for(int i=0; i<G.size(); i++)
      if(G[node][i] && visited.count(i) == 0)
        dfs(i, G, visited);
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    unordered_set<int>visited;
    int cnt = 0;
    for(int i=0; i<isConnected.size(); i++){
      if(visited.count(i))
        continue;
      dfs(i, isConnected, visited);
      cnt++;
    }
    return cnt;
  }
};