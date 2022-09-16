class Solution {
public:
    int dfs(int left, int ops, vector<int>&N, vector<int>&M, vector<vector<int>>&memo){
      if(ops == M.size())
        return 0;
      if(memo[left][ops] == INT_MIN){
        int i = left, j = N.size()-1-(ops-left);
        int sl = N[i]*M[ops] + dfs(left+1, ops+1, N, M, memo);
        int sr = N[j]*M[ops] + dfs(left, ops+1, N, M, memo);
        memo[left][ops] = max(sl, sr);
      }
      return memo[left][ops];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      vector<vector<int>>memo(1001, vector<int>(1001, INT_MIN));
      return dfs(0, 0, nums, multipliers, memo);
    }
};