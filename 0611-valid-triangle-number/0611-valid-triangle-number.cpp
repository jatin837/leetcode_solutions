class Solution {
public:
    int triangleNumber(vector<int>& nums) {
      if(nums.size() < 3)
        return 0;
      int ret = 0;
      sort(begin(nums), end(nums));
      for(int i=2; i<nums.size(); i++){
        int c = nums[i];
        // a + b > c
        // b > c - a
        for(int j=0; j<=i-2; j++){
          int a = nums[j];
          int b_indx = upper_bound(begin(nums)+j+1, begin(nums)+i, c-a) - begin(nums);
          if(b_indx > j && b_indx < i)
            ret += i-b_indx;
        }
      }
      return ret;
    }
};