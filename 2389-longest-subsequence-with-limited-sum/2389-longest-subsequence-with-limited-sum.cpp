class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
      vector<int>ans;
      sort(nums.begin(), nums.end());
      vector<int>preSum(nums.size(), 0);
      preSum[0] = nums[0];
      
      for(int i=1; i<nums.size(); i++)
        preSum[i] = preSum[i-1]+nums[i];
      
      vector<int>ret;
      for(int q:queries){
        int idx = upper_bound(preSum.begin(), preSum.end(), q)-preSum.begin();
        ret.push_back(idx);
      }
      return ret;
    }
};