class Solution {
public:
    int dfs(vector<vector<int>>&G, int i, vector<int>&q, vector<int>&memo){
      if(memo[i] != q.size())
        return memo[i];
      int ans = i;
      for(int child:G[i]){
        int pos = dfs(G, child, q, memo);
        if(q[pos] < q[ans])
          ans = pos;
      }
      memo[i] = ans;
      return ans;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
      vector<vector<int>>Graph(quiet.size());
      vector<int>ret(quiet.size(), quiet.size());
      for(auto v:richer)
        Graph[v[1]].push_back(v[0]);
      for(int i=0; i<quiet.size(); i++)
        ret[i] = dfs(Graph, i, quiet, ret);
      return ret;
    }
};