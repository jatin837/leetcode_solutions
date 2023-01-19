class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int tot = 0;
      int cnt = 0;
      unordered_map<int, int>mp;
      mp[0] = 1;
      for(int i=0; i<nums.size(); i++){
        tot += nums[i];
        cnt += mp[(k + tot%k)%k];
        mp[(k + tot%k)%k]++;
      }
      return cnt;
    }
};