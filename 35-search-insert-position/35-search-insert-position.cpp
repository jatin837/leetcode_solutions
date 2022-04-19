class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int l=0, r=nums.size()-1;
      int m = (r+l)>>1;
      while(l<=r) {
        if(nums[m]==target)
          return m;
        else if(nums[m]<target)
          l=m+1;
        else
          r=m-1;
        m = (l + r)>>1;
      }
      return l;
    }
};