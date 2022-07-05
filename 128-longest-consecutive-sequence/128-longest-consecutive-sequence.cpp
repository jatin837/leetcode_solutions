class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int>num_set(begin(nums), end(nums));
      int ans = 0;
      for(int num:num_set){
        if(!num_set.count(num-1)){
          int currNum = num;
          int currStreak = 1;
          while(num_set.count(currNum+1)){
            currStreak+=1;
            currNum+=1;
          }
          ans = max(ans, currStreak);
        }
      }
      return ans;
    }
};