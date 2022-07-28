class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int>ans(nums.size(), 1);
      int l = 1;
      for(int i=0; i<nums.size(); i++){
        ans[i] *= l;
        l *= nums[i];
      }
      int r = 1;
      for(int i=nums.size()-1; i>=0; i--){
        ans[i] *= r;
        r *= nums[i];
      }
      return ans;
    }
};