class Solution {
public:
    int reverse(int y) {
      int d = 0;
      int ans = 0;
      while(y){
        int d = y%10;
        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && d > INT_MAX%10))
          return 0;
        if(ans < INT_MIN/10 || (ans == INT_MIN/10 && d < INT_MIN%10))
          return 0;
        ans = 10*ans + d;
        y /= 10;
      }
      return ans;
    }
};