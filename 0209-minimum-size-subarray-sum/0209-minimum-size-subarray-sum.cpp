class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      vector<int>preSum(nums.size()+1, 0);
      int ret = INT_MAX;
      for(int i=1; i<=nums.size(); i++)
        preSum[i] += preSum[i-1] + nums[i-1];
      for(int i=1; i<=nums.size(); i++){
        int t = preSum[i]-target;
        int idx = upper_bound(begin(preSum), begin(preSum)+i, t) - begin(preSum) - 1;
        if(idx < 0 || idx > i)
          continue;
        ret = min(ret, i-idx);
      }
      return (ret==INT_MAX)?0:ret;
    }
};