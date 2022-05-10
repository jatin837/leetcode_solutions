class Solution {
public:
    int search(vector<int>& nums, int target) {
      int s = 0;
      int e = nums.size()-1;
      while(s<=e){
        int m = (s+e)>>1;
        if(nums[m]==target){
          return m; 
        }else if(nums[m] >= nums[s]){
           if(target >= nums[s] and target <= nums[m])
             e = m;
           else
             s = m+1;
        }else if(nums[m] <= nums[s]){
          if(target >= nums[m] and target <= nums[e])
            s = m+1;
          else
            e = m;
        }
      }
      return -1;
    }
};