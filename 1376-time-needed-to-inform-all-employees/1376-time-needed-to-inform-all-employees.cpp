class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      vector<vector<int>>G(n);
      for(int i=0; i<manager.size(); i++)
        if(manager[i] != -1)
          G[manager[i]].push_back(i);
      return dfs(G, headID, informTime);
    }
    int dfs(vector<vector<int>>&G, int root, vector<int>& informTime) {
      int t = informTime[root];
      int dt = 0;
      for(int child:G[root])
          dt = max(dt, dfs(G, child, informTime));
      return t+dt;
    }
};