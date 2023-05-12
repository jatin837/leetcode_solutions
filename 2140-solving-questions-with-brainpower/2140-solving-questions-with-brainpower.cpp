class Solution {
public:
  long long memo[100001];
  long long f(int i, vector<vector<int>>&qs){
    if(i >= qs.size())
      return 0;
    if(memo[i] == -1){
      long long ans1 = qs[i][0] + f(i+qs[i][1]+1, qs);
      long long ans2 = f(i+1, qs);
      memo[i] = max(ans1, ans2);
    }
    return memo[i];
  }
  long long mostPoints(vector<vector<int>>& questions) {
    memset(memo, -1, sizeof(memo));
    return f(0, questions);
  }
};