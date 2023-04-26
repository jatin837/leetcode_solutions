class Solution {
public:
    int addDigits(int num) {
      if(num < 10)
        return num;
      
      int res = 0;
      while(num){
        int d = num%10;
        res += d;
        num /= 10;
      }
      return addDigits(res);
    }
};