class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int>mp;
    int sum = nums[0];
    mp[nums[0]%k] = 1;
    for(int i=1; i<nums.size(); i++){
      sum += nums[i];
      if(sum%k == 0) 
        return true;
      if(mp[sum%k] > 0 && i - mp[sum%k] >= 1)
        return true;
      if(mp[sum%k] == 0)
        mp[sum%k] = i+1;
    }
    return false;
  }
};