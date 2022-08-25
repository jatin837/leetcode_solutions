class Solution {
public:
    int dfs(vector<vector<int>>&G, int i, vector<int>&q, vector<int>&memo){
      if(memo[i] != q.size())
        return memo[i];
      memo[i] = i;
      for(int child:G[i])
        if(q[dfs(G, child, q, memo)] < q[memo[i]])
          memo[i] = dfs(G, child, q, memo);
      return memo[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& q) {
      vector<vector<int>>G(q.size());
      vector<int>ret(q.size(), q.size());
      for(auto v:r)
        G[v[1]].push_back(v[0]);
      for(int i=0; i<q.size(); i++)
        ret[i] = dfs(G, i, q, ret);
      return ret;
    }
};