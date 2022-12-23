class Solution {
public:
    int memo[3002][3002];
    int dp(int i, int j, vector<int>&nums){
      if(i>j)
        return 0;
      if(i==j)
        return nums[i]*nums[i-1]*nums[i+1];
      if(memo[i][j] != -1)
        return memo[i][j];
      int ret = 0;
      for(int k=i; k<=j; k++){
        int curr = nums[k]*nums[i-1]*nums[j+1]+dp(i, k-1, nums)+dp(k+1, j, nums);
        ret = max(curr, ret);
      }
      memo[i][j] = ret;
      return memo[i][j];
    }
    int maxCoins(vector<int>& nums) {
      nums.insert(nums.begin(), 1);
      nums.insert(nums.end(), 1);
      memset(memo, -1, sizeof(memo));
      return dp(1, nums.size()-2, nums);
    }
};