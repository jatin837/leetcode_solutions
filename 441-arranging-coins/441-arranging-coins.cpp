class Solution {
public:
    int arrangeCoins(int n) {
      long long b = 0;
      long long e = n;
      while(b <= e){
        long long m = (b + e)>>1;
        if(m*(m+1)/2 == n)
          return m;
        if(m*(m+1)/2 < n)
          b = m+1;
        if(m*(m+1)/2 > n)
          e = m-1;
      }
      return e;
    }
};