class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums, vector<int>tmp, int idx){
      ans.push_back(tmp);
      for(int i=idx; i<nums.size(); i++){
        if(i > idx and nums[i] == nums[i-1])
          continue;
        tmp.push_back(nums[i]);
        backtrack(nums, tmp, i+1);
        tmp.pop_back();
      }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      backtrack(nums, {}, 0);
      return ans;
    }
};


//class Solution {
//public:
//    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
//    std::sort(nums.begin(), nums.end());
//        std::vector<std::vector<int> > res;
//    std::vector<int> vec;
//    subsets(res, nums, vec, 0);
//    return res;
//    }
//private:
//  void subsets(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
//    res.push_back(vec);
//    for (int i = begin; i != nums.size(); ++i) {
//      vec.push_back(nums[i]);
//      subsets(res, nums, vec, i + 1);
//      vec.pop_back();
//    }
//  }
//};