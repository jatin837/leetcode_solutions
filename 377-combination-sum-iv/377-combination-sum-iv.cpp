#define ull unsigned long long
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      unordered_map<ull, ull>dp;
      dp[0]=1;
      for(int i=1; i<=target; i++)
        for(auto num:nums)
          dp[i] += dp[i-num];
      return dp[target];
    }
};