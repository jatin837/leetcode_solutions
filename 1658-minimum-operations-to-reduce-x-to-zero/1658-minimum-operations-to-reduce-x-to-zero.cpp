/*
In my approach, I find the subarray of maximum length which is equal to the target.

Here, target is just the x subtracted from sum of array elements.

According to constraints of the problem, all values are positive, so, a prefix sum array will be strictly increasing.

Therefore, we can solve this using a sliding window on a prefix sum array.
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      // initialize the prefix sum array, this array will be of size one more then the numbers array. Doing this to avoid some edge cases.
      vector<int>pre(nums.size()+1);
      pre[0] = 0;
      
      // fill the prefix sum array
      for(int i=1; i<pre.size(); i++)
        pre[i] = pre[i-1] + nums[i-1];
      
      // initialize the left and right pointers equal to 0.
      int left = 0;
      int right = 0;
      
      // initialize the len of current subarray
      int sub_arr_len = 0; // we want to maximize this
      
      // initialize the boolean variable "found" which is handy to track if there were any sub array with sum equal to target 
      bool found = false;
      
      // compute our 'target', which is different as explained earilier
      int target = pre[pre.size()-1] - x;
      
      // if target is 0, which simply means that all sum of all elements from array is equal to x, then return length of numbers array
      if(target == 0)
        return nums.size();
      
      
      // time to slide the windows. Remember, prefix sum array has to be sorted, we can leverage this property to update window pointers
      while(left <= right and right < pre.size()){
        int curr_sum = pre[right] - pre[left];
        if(curr_sum == target){
          found = true;
          sub_arr_len = max(sub_arr_len, right-left);
          right++;
        }
        if(curr_sum < target)
          right++;
        if(curr_sum > target)
          left++;
      }
      if(not found)
        return -1;
      return nums.size()-sub_arr_len;
    }
};