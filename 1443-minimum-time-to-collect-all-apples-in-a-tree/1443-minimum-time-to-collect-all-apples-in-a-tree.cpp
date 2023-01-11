class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>&G, vector<bool>&hasApple){
      for(auto n:G[node]){
        if(n == parent)
          continue;
        dfs(n, node, G, hasApple);
      }
      for(int n:G[node])
        if(n != parent)
          hasApple[node] = hasApple[node] || hasApple[n];
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
      vector<vector<int>>G(n);
      for(auto e:edges)
        G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
      dfs(0, -1, G, hasApple);
      int cnt = 0;
      for(bool n:hasApple)
        cnt += n;
      return max(2*(cnt-1), 0);
    }
};