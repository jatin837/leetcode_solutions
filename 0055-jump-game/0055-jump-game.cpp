class Solution {
public:
  bool canJump(vector<int>& nums) {
    int next = 1;
    for(int i=0; i<nums.size(); i++){
      if(next){
        next = max(next-1, nums[i]);
        continue;
      }
      return false;
    }
    return true;
  }
};