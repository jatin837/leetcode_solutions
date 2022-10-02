class Solution {
public:
  int memo[31][1001];
  int numRollsToTarget(int n, int K, int target) {
    memset(memo, -1, sizeof(memo));
    return solve(n, K, target);
  }
  int solve(int n, int K, int target){
    int mod = 1e9+7;
    if(n == 1 && target > K)
      return 0;
    if(n == 1 && target <= K)
      return 1;
    if(memo[n][target] == -1){
      int ret = 0;
      for(int i=1; i<= min(K, target-1); i++)
        ret = (ret + solve(n-1, K, target-i))%mod;
      memo[n][target] = ret;
    }
    return memo[n][target];
  }
};