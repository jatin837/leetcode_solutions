class Solution {
public:
    int helper(vector<int>&nums, int currXOR, int idx){
      if (idx == nums.size())
        return currXOR;
      int withEl = helper(nums, nums[idx]^currXOR, idx+1);
      int withoutEl = helper(nums, currXOR, idx+1);
      return withEl + withoutEl;
        
    }
    int subsetXORSum(vector<int>& nums) {
      return helper(nums, 0, 0); 
    }
};