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
        int idx = lower_bound(preSum.begin(), preSum.end(), q)-preSum.begin();
        if(idx == nums.size()){
          ret.push_back(idx);    
          continue;
        }
        if(idx == -1){
          ret.push_back(0);
          continue;
        }
        if(preSum[idx] == q){
          ret.push_back(idx+1);
          continue;
        }
        ret.push_back(idx);
      }
      return ret;
    }
};