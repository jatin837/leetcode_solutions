class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
      int len = nums.size();
      if(k == 0) return (len > 0)?nums[0]:-1;
      if(k==1) return (len > 1)?nums[1]:-1;
      if(len == 1) return (k%2)?-1:nums[0];
      int mx = *max_element(nums.begin(), nums.begin() + min(k-1, len));
      if(k < len)
        mx = max(mx, nums[k]);
      return mx;
    }
};