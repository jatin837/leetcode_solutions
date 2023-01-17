class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<pair<int, int>>deg(n+1);
    if(n == 1)
      return 1;
    for(auto t:trust)
      deg[t[1]].first++,deg[t[0]].second++;
    int ret = -1;
    for(int i=0; i<deg.size(); i++)
      if((deg[i].first == n-1) && (deg[i].second == 0))
        if(ret != -1)
          return -1;
        else
          ret = i;
    return ret;
  }
};