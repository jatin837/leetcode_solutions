class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>&G, vector<bool>&hasApple){
      int tot = 0;
      int ctime = 0;
      for(auto n:G[node]){
        if(n == parent)
          continue;
        ctime = dfs(n, node, G, hasApple);
        tot += ctime;
        if(ctime || hasApple[n])
          tot += 2;
      }
      return tot;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
      vector<vector<int>>G(n);
      for(auto e:edges)
        G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
      return dfs(0, -1, G, hasApple);
    }
};