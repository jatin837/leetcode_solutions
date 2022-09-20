class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
      vector<int>dp(nums2.size()+1, 0);
      int ret = 0;
      for(int i=0; i<nums1.size(); i++){
        int curr = 0;
        int prev = 0;
        for(int j=0; j<nums2.size(); j++){
          if(nums1[i] == nums2[j])
            curr = dp[j]+int(nums1[i] == nums2[j]);
          else
            curr = 0;
          ret = max(ret, curr);
          dp[j] = prev;
          prev = curr;
        }
      }
      return ret;
    }
};