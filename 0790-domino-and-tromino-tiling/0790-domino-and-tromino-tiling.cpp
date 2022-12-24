class Solution {
public:
    int numTilings(int n) {
      long long dp10 = 1;
      long long dp11 = 0;
      long long dp20 = 2;
      long long dp21 = 1;
      long long dp31 = 1;
      long long dp30 = 1;
      int mod = 1e9+7;
      if(n == 1)
        return dp10;
      if(n == 2)
        return dp20;
      for(int i=3; i<=n; i++){
        dp30 = (dp20 + dp10 + 2*dp21)%mod;
        dp31 = (dp21 + dp10)%mod;
        dp10 = (dp20)%mod;
        dp11 = (dp21)%mod;
        dp20 = (dp30)%mod;
        dp21 = (dp31)%mod;
      }
      return dp30;
    }
};