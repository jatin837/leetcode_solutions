class Solution {
public:
  int fib(int n) {
    if (n == 1)
      return 1;
    if (n == 0)
      return 0;
    
    int f0 = 0;
    int f1 = 1;
    int temp=0;
    for (int i=2; i<n; i++){
      temp = f0 + f1;
      f0 = f1;
      f1 = temp;
      temp = 0;
    }
    return f0 + f1;
  }
};