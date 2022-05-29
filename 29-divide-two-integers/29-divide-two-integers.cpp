class Solution {
public:
    int divide(int dividend, int divisor) {
      long divd = labs(dividend);
      long divr = labs(divisor);
      if (divd<divr)
        return 0;
      bool neg = (dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0);
      
      if (dividend == INT_MIN and !neg)
        divd -= 1;
      
      long s = 1;
      long e = divd;
      long m = (s+e)>>1;
      
      if (divr == 1)
        if(neg)
          return -1*divd;
        else
          return divd;
      while(s<e){
        if(divd - m*divr >= 0 and divd - (m+1)*divr < 0){
          if(neg)
            return -1*m;
          return m;
        }else if(divd - m*divr > 0 and divd - (m+1)*divr > 0)
          s = m+1;
        else
          e = m-1;
        m = (s+e)>>1;
      }
      if(neg)
        return -1*s;
      return s;
    }
};