class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int tot = accumulate(nums.begin(), nums.end(), 0);
      int left = 0;
      for(int i=0; i<nums.size(); i++){
        int num = nums[i];
        int right = tot - left - num;
        if(left == right)
          return i;
        left += num;
      }
      return -1;
    }
};