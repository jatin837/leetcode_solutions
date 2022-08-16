#define MAX_SUM 20001
#define MAX_NUM 201

class Solution {
public:
    bool dp(int target, int pos, vector<int>&A){
      vector<bool>memo(target+1, false);
      memo[0]=true;
      for(int n:A)
        for(int sum = target; sum > 0; sum--)
          if(sum>=n)
            memo[sum] = memo[sum] || memo[sum-n];
      return memo[target];
    }
    bool canPartition(vector<int>& nums) {
      int target = accumulate(nums.begin(), nums.end(), 0);
      if(target%2)
        return false;
      target >>= 1;
      return dp(target, nums.size(), nums);
    }
};