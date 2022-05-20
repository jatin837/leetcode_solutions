class Solution {
public:
    int titleToNumber(string columnTitle) {
      int ans=0;
      int len = columnTitle.length();
      int i=len-1;
      long long int base = 1;
      while(i>=0){
        int ch = columnTitle[i--];
        int dig = (ch-int('A'))+1;
        ans += dig*base;
        base*=26;
      }
      return ans;
    }
};