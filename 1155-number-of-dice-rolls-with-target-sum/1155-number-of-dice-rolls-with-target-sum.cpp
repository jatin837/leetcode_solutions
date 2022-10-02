class Solution {
public:
  int numRollsToTarget(int n, int K, int target) {
    vector<vector<int>>memo(n+1, vector<int>(target+1, -1));
    return numRollsToTarget(n, K, target, memo);
  }
  int numRollsToTarget(int n, int K, int target, vector<vector<int>>&memo){
    int mod = 1e9+7;
    if(n == 1 && target > K)
      return 0;
    if(n == 1 && target <= K)
      return 1;
    if(memo[n][target] == -1){
      int ret = 0;
      
      for(int i=1; i<= min(K, target-1); i++)
       ret = (ret + numRollsToTarget(n-1, K, target-i, memo))%mod;
      
      memo[n][target] = ret;     
    }
    return memo[n][target]; 
  }
};