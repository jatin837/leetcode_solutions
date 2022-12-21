class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      vector<int>preSum(nums.size(), 0);
      preSum[0] = nums[0];
      for(int i=1; i<nums.size(); i++)
        preSum[i] += preSum[i-1] + nums[i];
      for(int i=0; i<nums.size(); i++){
        int leftSum = (i==0)?0:preSum[i-1];
        int rightSum = preSum.back() - preSum[i];
        if(leftSum == rightSum)
          return i;
      }
      return -1;
    }
};