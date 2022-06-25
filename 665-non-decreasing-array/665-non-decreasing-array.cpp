class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      int len = nums.size();
      if(nums.size() == 1)
        return true;
      int cnt = 0;
      if(nums[0] > nums[1]){
        nums[0] = nums[1];
        cnt++;
      }
      for(int i=1; i<len-1; i++){
        if(nums[i] <= nums[i+1]) 
          continue;
        if(cnt == 1)
          return false;
        if(nums[i-1] <= nums[i+1])
          nums[i] = nums[i+1];
        else
          nums[i+1] = nums[i];
        cnt++;
      }
      return true;
    }
};