class Solution {
public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    vector<int>ans;
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++)
      nums[i] += nums[i-1];
    vector<int>ret;
    for(int q:queries)
      ret.push_back(upper_bound(nums.begin(), nums.end(), q)-nums.begin());
    return ret;
  }
};