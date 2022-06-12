/* 
This is a really simple and pretty much efficient solution.
I used sliding window technique with prefix sum array.
During my submission time, it was faster than 90% submissions and memory usage was 60% less then other submission
Hope I was useful guys.
Thanks for reading.
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      vector<int> pre(nums.size()+1);
      
      // prefix sum array;
      pre[0] = 0;
      for(int i=1; i<pre.size(); i++)
        pre[i] = pre[i-1] + nums[i-1];
      
      // mapping  current element with it's index
      unordered_map<int, int>idx;
      
      // initialize left and right ends of window
      int left = 0;
      int right = 1;
      
      // initialize 'sum' as our local sum of subarray
      // we have to maximize
      // since we need to have unique subarray elements, therefore, it must contain atleast one element
      int sum = nums[0];
      
      // initialize current element(which is index 0) index to one
      // Note: for each element, we will set index to 1 more then it's current index
      // the reason is if rightmost element is already present in our candidate solution, then, we need to update our left pointer to (previous index of this element + 1), so, we can directly store it here anyway
      idx[nums[0]] = 1;
      // global optimum variable
      int best = 0;
      
      // we'll be conditionally sliding left and right end of the window
      while(right < nums.size()){
        // if index of rightmost element is greater or equal to left pointer, then we need to update our left pointer to this pointer, since any candidate solution which has this number is invalid by definition
        if(idx[nums[right]] >= left)
          left = idx[nums[right]];
        
        // calculate the sum of current subarray (which is valid);
        sum = pre[right+1] - pre[left];
        idx[nums[right]] = right+1;
        
        // always update the right pointer;
        right++;
        // compute the global maximum
        best = max(sum, best);
      }
      // if length of input is 1, then above loop won't run, this is why we need this final check
      best = max(sum, best);
      return best;
    }
};