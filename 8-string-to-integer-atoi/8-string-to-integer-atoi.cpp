class Solution {
public:
    int myAtoi(string s) {
      int b = 0;
      int sign = 1;
      
      while(s[b] == ' ' and b < s.length())
        b++;
      
      int ans = 0;
      
      if(s[b] == '-' and b < s.length()){
        sign = -1;
        b++;
      }
      else if(s[b] == '+' and b < s.length()){
        sign = 1;
        b++;
      }
      else
        sign = 1;
      
      while(b++ < s.length() and isdigit(s[b-1])){
        int dig = s[b-1]-'0';
        if((ans > INT_MAX/10) or (ans == INT_MAX/10 and dig > 7))
          return sign == 1 ? INT_MAX:INT_MIN;
        ans = 10*ans + dig;
      }
      return sign*ans;
    }
};