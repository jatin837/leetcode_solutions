class Solution {
public:
    void dfs(vector<vector<int>>&G, int pos, vector<int>&status){
      if(status[pos] == 2){
        status[pos] = -1; 
        return;
      }
      if(status[pos] == 1 || status[pos]==-1)
        return;
      if(status[pos] == 0){
        status[pos] = 2;
        if(G[pos].size()==0){
          status[pos] = 1;
          return;
        }
        for(int n:G[pos])
          if(status[n] == 0)
            dfs(G, n, status);
        for(int n:G[pos])
          if(status[n] == -1 || status[n] == 2){
            status[pos] = -1;
            return;
          }
        status[pos] = 1;       
      }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      vector<int>ans;
      vector<int>status(graph.size(), 0);
      for(int i=0; i<graph.size(); i++){
        dfs(graph, i, status);
        if(status[i] == 1)
          ans.push_back(i);
      }
      return ans;
    }
};