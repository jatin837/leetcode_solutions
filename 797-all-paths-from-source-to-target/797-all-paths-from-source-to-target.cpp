class Solution {
public:
    vector<vector<int>>dfs(vector<vector<int>>& g, int node){
      if(node == g.size()-1)
        return {{node}};
      vector<vector<int>>ans;
      for(int n:g[node])
        for(auto gn:dfs(g, n)){
          gn.insert(gn.begin(), node);
          ans.push_back(gn);
        }
      return ans;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      return dfs(graph, 0);
    }
};