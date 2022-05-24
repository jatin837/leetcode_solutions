//class Solution {
//public:
//    double myPow(double x, int n) {
//      if(n<0){
//        if(abs(n) >= INT_MAX)
//          n = INT_MAX;
//        else
//          n = -1*n; 
//        x = 1/x;
//      }
//      double res = 1;
//      while (n > 0) {
//        if (n & 1)
//            res = res * x;
//        x = x * x;
//        n >>= 1;
//      }
//      return res;
//    }
//};

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }
};
