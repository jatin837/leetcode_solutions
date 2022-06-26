class Solution {
public:
    int countHousePlacements(int n) {
      long long f0 = 2;
      long long f1 = 3;
      long long mod = 1e9+7;
      if(n==1)
        return f0*f0;
      if(n==2)
        return f1*f1;
      for(int i=3; i<=n; i++){
        long long tmp = (f0 + f1)%mod;
        f0 = f1;
        f1 = tmp;
        cout<<f1<<'\n';
      }
      return 1L*f1*f1%mod;
    }
};