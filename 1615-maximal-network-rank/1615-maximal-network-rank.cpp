class Solution {
public:
  bool connected[101][101];
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<vector<int>>G(n);
    for(vector<int>r:roads)
      G[r[0]].push_back(r[1]),G[r[1]].push_back(r[0]);
    memset(connected, false, sizeof(connected));
    for(int i=0; i<G.size(); i++)
      for(int c:G[i])
        connected[i][c] = true;
    int ret = 0;
    for(int i=0; i<G.size(); i++)
      for(int j=i+1; j<G.size(); j++)
        ret = max(ret, (int)G[i].size() + (int)G[j].size() - connected[i][j]);
    return ret;
  }
};