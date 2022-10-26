class Solution {
public:
  int next(int n){
    int sum = 0;
    while(n){
      int d = n%10;
      sum += d*d;
      n/=10;
    }   
    return sum;
  }
  bool isHappy(int n) {
    int slow = n;
    int fast = next(n);
    while(fast != slow){
      if(slow == 1 || fast == 1)
        return true;
      slow = next(slow);
      fast = next(next(fast));
    }
    return slow == 1 || fast == 1;
  }
};