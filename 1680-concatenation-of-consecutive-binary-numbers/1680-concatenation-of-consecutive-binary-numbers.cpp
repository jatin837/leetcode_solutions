class Solution {
public:
  int concatenatedBinary(int n) {
    long tmp = 0;
    int shift = 0;
    int MOD = 1e9+7;
    for(int i=1; i<=n; i++){
      if(__builtin_popcount(i) == 1)
        shift++;
      tmp = ((tmp<<shift)|i)%MOD;
    }
    return tmp;
  }
};