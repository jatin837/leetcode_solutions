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
        for(int i=0; i<preSum.size(); i++){
          if(preSum[i] > q){
            ret.push_back(i);
            break;
          }
          if(i == nums.size()-1)
            ret.push_back(i+1);
        }
      }
      return ret;
    }
};