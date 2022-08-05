#define ull unsigned long long
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      vector<ull>dp(target+1);
      dp[0]=1;
      for(int i=1; i<=target; i++)
        for(auto num:nums)
          dp[i] += (i-num>=0)?dp[i-num]:0;
      return dp[target];
    }
};