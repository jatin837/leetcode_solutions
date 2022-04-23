class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> ans(2, -1);
      if(nums.size() == 0)
        return ans;
      int b = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
      int e = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
      if(b == nums.size())
        return ans;
      if(nums[b] != target)
        return ans;
      ans[0] = b;
      ans[1] = e-1;
      return ans;
    }
};