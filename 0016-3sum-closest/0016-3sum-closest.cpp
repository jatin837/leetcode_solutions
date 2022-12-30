class Solution {
public:
  int diff(int a, int b){
    return abs(a-b);
  }
  int nSumClosest(int n, vector<int>&nums, int beg, int end, int target){
    if(n == 2)
      return twoSumClosest(nums, beg, end, target);
    int i=beg;
    int d = INT_MAX;
    int ret = 0;
    while(i<=end-n+1){
      int sum = nums[i] + nSumClosest(n-1, nums, i+1, end, target-nums[i]);
      if(d > diff(sum, target)){
        d = diff(sum, target);
        ret = sum;
      }
      i++;
    }
    return ret;
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
    return nSumClosest(3, nums, 0, nums.size()-1, target);
  }
};