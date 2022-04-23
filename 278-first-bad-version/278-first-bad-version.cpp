// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      long long b = 1;
      long long e = n;
      if(n == 1)
        return 1;
      unsigned long long m = (b + e)>>1;
      while(b <= e){
        if(isBadVersion(m))
          e = m-1;
        else
          b = m + 1;
        m = (e + b)>>1;
      }
      return b;
    }
};