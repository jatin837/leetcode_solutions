class Solution {
  long long memo[1001][2];
  int mod=1e9+7;
  long long f(int len, int type){
    if(len == 1 and type == 0)
      return 1;
    if(len == 1 and type == 1)
      return 0;
    if(len == 2 and type == 0)
      return 2;
    if(len == 2 and type == 1)
      return 1;
    if(memo[len][type] != -1)
      return memo[len][type];
    if(type == 0)
      memo[len][type] = (f(len-1, 0) + f(len-2, 0) + 2*f(len-1, 1))%mod;
    else
      memo[len][type] = (f(len-2, 0) + f(len-1, 1))%mod;
    return memo[len][type];
  }
public:
    int numTilings(int n) {
      memset(memo, -1, sizeof(memo));
      return f(n, 0);
    }
};