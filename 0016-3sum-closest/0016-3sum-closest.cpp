class Solution {
public:
  int diff(int a, int b){
    return abs(a-b);
  }
  int twoSumClosest(vector<int>&nums, int beg, int end, int target){
    if(end-beg == 1)
      return nums[beg]+ nums[end];
    int d = INT_MAX;
    int ret = 0;
    while(beg < end){
      int sum = nums[beg] + nums[end];
      if(sum == target)
        return sum;
      if(nums[beg] + nums[end] > target)
        end--;
      else
        beg++;
      if(diff(sum, target) < d){
        d = diff(sum, target);
        ret = sum;
      }
    }
    return ret;
  }
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ret = 0;
    int d = INT_MAX;
    for(int i=0; i<nums.size()-2; i++){
      int cand = nums[i] + twoSumClosest(nums, i+1, nums.size()-1, target-nums[i]);
      if(diff(cand, target) < d){
        d = diff(cand, target);
        ret = cand;
      }
    }
    return ret;
  }
};