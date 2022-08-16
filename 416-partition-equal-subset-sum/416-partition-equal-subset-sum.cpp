#define MAX_SUM 20001
#define MAX_NUM 201

class Solution {
public:
    bool dp(int target, int pos, vector<int>&A){
      bool memo[MAX_SUM][MAX_NUM];
      bool ans = false;
      for(int i=0; i<=A.size(); i++)
        memo[0][i]=true;
      for(int sum = 1; sum <= target; sum++){
        ans = false;
        for(int i=0; i<A.size(); i++){
          bool include, exclude;
          exclude = memo[sum][i];
          if(sum-A[i] < 0)
            include = false;
          else
            include = memo[sum-A[i]][i];
          memo[sum][i+1] = include || exclude;
          ans = ans or memo[sum][i+1];
        }
      }
      return ans;
    }
    bool canPartition(vector<int>& nums) {
      int target = accumulate(nums.begin(), nums.end(), 0);
      if(target%2)
        return false;
      target >>= 1;
      return dp(target, nums.size(), nums);
    }
};