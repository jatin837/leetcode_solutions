class Solution {
public:
    int minimumSum(int num) {
      
      vector<int>digits(4);
      for(int i=0; i<4; i++){
        int d = num%10;
        digits[i]=d;
        num /= 10;
      }
      sort(begin(digits), end(digits));
      int ans = 0;
      ans += digits[0]*10 + digits[2];
      ans += digits[1]*10 + digits[3];
      return ans;
    }
};