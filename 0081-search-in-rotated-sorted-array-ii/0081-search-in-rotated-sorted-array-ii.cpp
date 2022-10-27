class Solution {
public:
  bool search(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    if(lower_bound(nums.begin(), nums.end(), target) == nums.end())
      return false;
    return *lower_bound(nums.begin(), nums.end(), target) == target;
  }
};