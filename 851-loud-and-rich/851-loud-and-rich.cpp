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