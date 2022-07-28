class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int>pre(nums.size());
      vector<int>suff(nums.size());
      pre[0] = nums[0];
      suff[suff.size()-1] = nums.back();
      for(int i=1; i<nums.size(); i++){
        pre[i] = pre[i-1]*nums[i];
        suff[nums.size()-i-1] = suff[nums.size()-i]*nums[nums.size()-i-1];
      }
      for(int i=0; i<nums.size(); i++)
        nums[i] = (i?pre[i-1]:1)*((i+1<nums.size())?suff[i+1]:1);
      return nums;
    }
};