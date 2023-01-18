class Solution {
public:
  int kadan(vector<int>&arr, bool mx){
    int sum = arr[0];
    int best = arr[0];
    for(int i=1; i<arr.size(); i++){
      if(mx){
        sum = max(arr[i], sum + arr[i]);
        best = max(sum, best);
      }else{
        sum = min(arr[i], sum + arr[i]);
        best = min(sum, best);
      }
    }
    return best;
  }
  int maxSubarraySumCircular(vector<int>& nums) {
    // find the subarray sum which is maximum(s1) and minimum(s2)
    // than, return the max of (s1, s-s2)
    // where s is the sum of the whole array
    int s1 = kadan(nums, true);
    int s2 = accumulate(begin(nums), end(nums), 0) - kadan(nums, false);
    if(s2 == 0)
      return s1;
    return max(s1, s2);
  }
};