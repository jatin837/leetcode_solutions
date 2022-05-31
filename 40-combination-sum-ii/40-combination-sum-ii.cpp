class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>&nums,
                   vector<int> tmp,
                   int sum,
                   int target,
                   int idx){
      
      if (sum == target){
        ans.push_back(tmp);
        return;
      }
      
      if (sum > target)
        return;
      
      if (idx == nums.size())
        return;
      
      for(int i=idx; i<nums.size(); i++){
       if(i > idx and nums[i] == nums[i-1])
         continue;
       tmp.push_back(nums[i]);
        backtrack(
          nums,
          tmp,
          sum + nums[i],
          target,
          i+1
        );
        tmp.pop_back();
      }
    }
  
  
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      backtrack(candidates, {}, 0, target, 0);
      return ans;
    }
};