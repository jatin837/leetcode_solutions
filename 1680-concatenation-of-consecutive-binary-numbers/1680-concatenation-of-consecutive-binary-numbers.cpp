class Solution {
public:
  int concatenatedBinary(int n) {
    long ret = 0;
    int shift = 0;
    int MOD = 1e9+7;
    for(int i=1; i<=n; i++){
      if((i&(i-1))==0)
        shift++;
      ret = ((ret<<shift)|i)%MOD;
    }
    return ret;
  }
};