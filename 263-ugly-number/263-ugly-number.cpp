class Solution {
public:
    bool isUgly(int n) {
      if(n==1)
        return true;
      if(n==0)
        return false;
      int ugly = false;
      if(n%2 == 0){
        ugly = true;
        n/=2;
      }
      if(n%3 == 0){
        ugly = true;
        n/=3;
      }
      if(n%5 == 0){
        ugly = true; 
        n/=5;
      }
      if(not ugly)
        return false;
      return isUgly(n);
    }
};