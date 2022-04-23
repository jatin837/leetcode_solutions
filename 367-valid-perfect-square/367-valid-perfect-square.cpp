class Solution {
public:
    bool isPerfectSquare(int num) {
      unsigned int b = 0;
      unsigned int e = num;
      unsigned long long int m = (b+e)>>1;
      while(b <= e){
        if(m*m == num){
          return true;
        }
        else if(m*m > num)
          e = m-1;
        else
          b = m+1;
        m = (b + e)>>1;
      }
      return false;
    }
};