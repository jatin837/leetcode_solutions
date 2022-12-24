class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int cand, cnt;
      cand = nums[0];
      cnt = 1;
      for(int i=1; i<nums.size(); i++){
        if(nums[i] == cand){
          cnt++;
          continue;
        }
        cnt--;
        if(cnt == 0){
          cand = nums[i]; 
          cnt = 1;
        }
      }
      return cand;
    }
};