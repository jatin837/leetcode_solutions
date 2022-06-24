class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> mp;
      for(int i=0; i<nums.size(); i++){
        int a = nums[i];
        int b = target - a;
        if(mp[b] > 0)
          return {i, mp[b]-1};
        mp[a] = i+1;
      }
      return {0, 0};
  }
};
