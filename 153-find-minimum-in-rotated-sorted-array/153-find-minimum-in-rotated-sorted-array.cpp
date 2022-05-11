class Solution {
public:
    int findMin(vector<int>& nums) {
      int s = 0;
      int e = nums.size()-1;
      int m = 0;
      if(nums.size() == 1)
        return nums[0];
      if(nums[0] < nums[e])
        return nums[0];
      while(s<=e){
        m = (s+e)>>1;
        if(nums[m] > nums[m+1])
          return nums[m+1];
        if(nums[m] < nums[m-1])
          return nums[m];
        if(nums[m] > nums[0])
          s = m+1;
        else
          e = m-1;
      }
      
      return -1;
    }
};