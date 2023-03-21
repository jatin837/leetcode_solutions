class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      long long ret = 0;
      long long curr = 0;
      long long prev = 0;
      for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0){
          curr += 1;
          prev += 1;
        }else
          curr = 0;
        if(curr != prev){
          ret += long(prev*(prev+1)*0.5);
          curr = 0;
          prev = 0;
        }
      }
      ret += long(prev*(prev+1)*0.5);
      return ret;
    }
};