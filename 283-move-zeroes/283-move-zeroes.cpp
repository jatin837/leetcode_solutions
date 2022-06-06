class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int zeroCnt = 0;
      for(auto num:nums)
        if(num==0)
          zeroCnt++;
      for(int j=0; j<zeroCnt; j++){
        for(int i=0; i<nums.size()-1; i++){
          if(nums[i] == 0)
            swap(nums[i], nums[i+1]);
        }       
      }

    }
};