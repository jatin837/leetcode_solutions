class Solution {
public:
    int maxProduct(vector<int>& nums) {
      sort(begin(nums), end(nums));
      int len = nums.size();
      return (nums[len-1]-1)*(nums[len-2]-1);
    }
};