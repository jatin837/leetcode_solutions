class Solution {
public:
    int specialArray(vector<int>& nums) {
      int N = nums.size();
      sort(nums.begin(), nums.end());
      for(int i=0; i<=nums[N-1]; i++){
        int x = N - (lower_bound(nums.begin(), nums.end(), i) - nums.begin());
        if (x == i)
          return x;
      }
      return -1;
    }
};