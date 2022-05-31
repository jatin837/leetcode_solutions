class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>& nums, vector<int> tmp, int sum, int target, int idx){
      if (sum == target){
        ans.push_back(tmp);
        return;
      }if (sum > target)
        return;
      for(int i=idx; i<nums.size(); i++){
        tmp.push_back(nums[i]);
        backtrack(nums, tmp, sum + nums[i], target, i);
        tmp.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      backtrack(candidates, {}, 0, target, 0);
      return ans;
    }
};