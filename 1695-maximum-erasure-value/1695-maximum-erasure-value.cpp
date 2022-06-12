class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      /*
      we need to find a subarray with maximum sum and unique sum.
      it's pretty clear that we need to use a hashmap to keep track of the index of element
      
      we will use sliding window method
      */
      vector<int> pre(nums.size()+1);
      
      // prefix sum array;
      pre[0] = 0;
      for(int i=1; i<pre.size(); i++)
        pre[i] = pre[i-1] + nums[i-1];
      
      unordered_map<int, int>idx;
      
      int left = 0;
      int right = 1;
      int sum = nums[0];
      idx[nums[0]] = 1;
      int best = 0;
      while(right < nums.size()){
        if(idx[nums[right]] >= left)
          left = idx[nums[right]];
        sum = pre[right+1] - pre[left];
        idx[nums[right]] = right+1;
        right++;
        best = max(sum, best);
      }
      best = max(sum, best);
      return best;
    }
};