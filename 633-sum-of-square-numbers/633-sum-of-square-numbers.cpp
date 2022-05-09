class Solution {
public:
    bool judgeSquareSum(int c) {
      if(c == 0)
        return true;
      for(long long int a = 0; a*a<c; a++){
        long long int bsq = c-a*a;
        long long int s = 0;
        long long int e = bsq;
        long long int m = (s+e)>>1;
        while(s <= e){
          if(m*m == bsq)
            return true;
          if(m*m > bsq)
            e = m-1;
          if(m*m < bsq)
            s = m + 1;
          m = (s + e)>>1;
        }
      }
      return false;
    }
};