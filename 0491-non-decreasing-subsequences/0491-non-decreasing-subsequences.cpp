class Solution {
public:
  set<vector<int>>ret;
  void dfs(vector<int>&nums, int i, vector<int>sq){
    if(i == nums.size()){
      if(sq.size() >= 2)
        ret.insert(sq);
      return;
    }
    dfs(nums, i+1, sq);
    if(sq.size() == 0 || sq.back() <= nums[i]){
      sq.push_back(nums[i]);
      dfs(nums, i+1, sq);
    }
  }
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    dfs(nums, 0, {});
    return vector(ret.begin(), ret.end());
  }
};