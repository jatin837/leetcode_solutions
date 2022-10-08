class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int len = nums.size();
      int ans = nums[0] + nums[1] + nums[2];
      int diff = INT_MAX; 
      for(int i=0; i<len-2; i++){
        int l = i+1;
        int h = len-1;
        while(l<h){
         int curr_sum = nums[l] + nums[h] + nums[i];
         if(curr_sum ==  target)
            return target;
          else if(curr_sum < target)
            l++;
          else
            h--;
          if(abs(curr_sum - target) < diff){
            ans = curr_sum;
            diff = abs(ans-target);
          }
        }
        
      }
      return ans;
    }
};