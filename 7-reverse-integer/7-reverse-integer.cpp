class Solution {
public:
    int reverse(int x) {
      int d = 0;
      long long int ans = 0;
      bool neg = x<0?true:false;
      int y = abs(x);
      while(y){
        d = y%10;
        if(ans > INT_MAX/10 or (ans == INT_MAX/10 and d > 7))
          return 0;
        if(ans < INT_MIN/10 or (ans == INT_MIN/10 and d < -8))
          return 0;
        ans = d + 10*ans;
        y /= 10;
        cout<<ans<<'\n';
      }
      if(neg)
        return -1*ans;
      return ans;
    }
};