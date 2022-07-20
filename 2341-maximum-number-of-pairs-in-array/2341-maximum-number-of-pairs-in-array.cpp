class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
      vector<int>ans(2, 0);
      sort(begin(nums), end(nums));
      int i = 0;
      int j = 0;
      while(i < nums.size() and j < nums.size()){
        while(j < nums.size() and nums[j] == nums[i])
          j++;
        ans[0] += (j-i)>>1;
        if((j-i)%2)
          ans[1]++;
        i=j;
      }
      return ans;
    }
};