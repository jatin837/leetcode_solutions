class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int>in(n+1);
    vector<int>out(n+1);
    if(n == 1)
      return 1;
    for(auto t:trust)
      in[t[1]]++,out[t[0]]++;
    int ret = -1;
    for(int i=0; i<in.size(); i++)
      if((in[i] == n-1) && (out[i] == 0))
        if(ret != -1)
          return -1;
        else
          ret = i;
    return ret;
  }
};