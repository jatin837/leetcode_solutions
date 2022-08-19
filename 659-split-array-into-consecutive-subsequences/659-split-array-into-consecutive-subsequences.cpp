class Solution {
public:
    bool isPossible(vector<int>& nums) {
      unordered_map<int, int>left, need;
      for(int n:nums)
        left[n]++;
      for(int i=0; i<nums.size(); i++){
        int currNum = nums[i];
        if(left[currNum]){
          if(need[currNum]){
            need[currNum]--;
            left[currNum]--;
            need[currNum+1]++;
            continue;
          }
          if(left[currNum+1] && left[currNum+2]){
            left[currNum]--;
            left[currNum+1]--;
            left[currNum+2]--;
            need[currNum+3]++;
            continue;
          }
          return false;         
        }
      }
      return true;
    }
};