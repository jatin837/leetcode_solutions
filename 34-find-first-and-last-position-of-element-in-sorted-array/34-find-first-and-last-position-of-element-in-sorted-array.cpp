class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
  if(nums.size() == 0)
    return {-1, -1};
  int b = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  int e = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
  if(b == nums.size() or nums[b] != target)
    return {-1, -1};
  return {b, e-1};
}
};