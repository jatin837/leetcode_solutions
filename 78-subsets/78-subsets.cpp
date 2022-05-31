class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int idx, vector<int>tmp, vector<int>&nums){
      ans.push_back(tmp);
      for(int i=idx; i<nums.size(); i++){
        tmp.push_back(nums[i]);
        backtrack(i+1, tmp, nums);
        tmp.pop_back();
      }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      backtrack(0, {}, nums);
      return ans;
    }
};