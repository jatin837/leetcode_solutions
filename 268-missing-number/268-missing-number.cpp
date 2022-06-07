class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int len = nums.size();
      int xor_ = 0;
      for(int i=0; i<=len; i++)
        xor_ ^= i;
      for(int i=0; i<len; i++)
        xor_ ^= nums[i];
      return xor_;
    }
};