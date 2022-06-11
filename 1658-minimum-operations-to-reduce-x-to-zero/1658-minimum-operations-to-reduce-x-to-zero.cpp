class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      vector<int>pre(nums.size()+1);
      pre[0] = 0;
      int l = 0;
      int r = 1;
      int ans = 0;
      bool found = false;
      for(int i=1; i<pre.size(); i++)
        pre[i] = pre[i-1] + nums[i-1];
      int target = pre[pre.size()-1] - x;
      if(target == 0)
        return nums.size();
      while(l <= r and r < pre.size()){
        int curr_sum = pre[r] - pre[l];
        if(curr_sum == target){
          found = true;
          ans = max(ans, r-l);
          r++;
        }
        if(curr_sum < target)
          r++;
        if(curr_sum > target)
          l++;
      }
      if(not found)
        return -1;
      return nums.size()-ans;
    }
};