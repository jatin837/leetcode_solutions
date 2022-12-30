class Solution {
public:
    void twoSum(vector<int>& nums, int l, int h, int target, vector<vector<int>>&ans){
      while(l < h){
        if(nums[l] + nums[h] == target){
          ans.push_back({-target, nums[l], nums[h--]});
          while(h>l && nums[h] == nums[h+1])
            h--;
        }
        else if(nums[l] + nums[h] > target)
          h--;
        else
          l++;
      }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
      int len = nums.size();
      sort(nums.begin(), nums.end());
      vector<vector<int>> ans;
      int i=0;
      while(i < len){
        int l = i+1, h = len-1;
        twoSum(nums, l, h, -nums[i], ans);
        while(i+1 < len && nums[i] == nums[i+1])
          i++;
        i++;
      }
      return ans;
    }
};