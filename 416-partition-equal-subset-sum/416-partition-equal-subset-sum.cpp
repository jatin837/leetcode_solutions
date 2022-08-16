class Solution {
public:
    int memo[20001][201];
    bool dp(int sum, int pos, vector<int>&A){
      if(sum == 0)
        return true;
      if(sum < 0 || pos == 0)
        return false;
      if(memo[sum][pos]==0){
        memo[sum][pos] = 1; 
        memo[sum][pos] += dp(sum-A[pos-1], pos-1, A) || dp(sum, pos-1, A);
      }
      return memo[sum][pos]==2;
    }
    bool canPartition(vector<int>& nums) {
      int target = accumulate(nums.begin(), nums.end(), 0);
      if(target%2)
        return false;
      target >>= 1;
      return dp(target, nums.size(), nums);
    }
};