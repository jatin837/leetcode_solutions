class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int cand=-1, cnt=1;
      for(int i=0; i<nums.size(); i++){
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