class Solution {
public:
  int sumSq(int n){
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
    int fast = sumSq(n);
    while(fast != slow){
      if(slow == 1 || fast == 1)
        return true;
      slow = sumSq(slow);
      fast = sumSq(sumSq(fast));
    }
    return slow == 1 || fast == 1;
  }
};