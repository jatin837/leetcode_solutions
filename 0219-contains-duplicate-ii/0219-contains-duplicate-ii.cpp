class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      int len = nums.size();
      unordered_map<int, int> mp;
      for(int i=0; i<len; i++){
        if(mp[nums[i]] != 0 and i-mp[nums[i]]+1 <= k)
          return true;
        mp[nums[i]] = i+1;
      }
      return false;
    }
};