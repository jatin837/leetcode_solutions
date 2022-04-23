class Solution {
public:
    int mySqrt(int num) {
      unsigned int b = 0;
      unsigned int e = num;
      unsigned long long int m = (b+e)>>1;
      
      if(num == 0 or num == 1)
        return num;
      
      while(b <= e){
        if(m*m == num){
          return m;
        }
        else if(m*m > num)
          e = m-1;
        else
          b = m+1;
        m = (b + e)>>1;
      }
      
      return m;
    }
};