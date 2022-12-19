class Solution {
public:
    bool dfs(vector<vector<int>>&G, int node, int dest, unordered_set<int>& visited){
      bool ret = false;
      if(node == dest){
        ret = true;
      }
      else{
        visited.insert(node);
        for(int n:G[node]){
          if(!visited.count(n))
            ret = ret || dfs(G, n, dest, visited);
        }
      }
      return ret;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<vector<int>>G(n);
      for(auto edge:edges)
        G[edge[0]].push_back(edge[1]),G[edge[1]].push_back(edge[0]);
      unordered_set<int>visited;
      return dfs(G, source, destination, visited);
    }
};