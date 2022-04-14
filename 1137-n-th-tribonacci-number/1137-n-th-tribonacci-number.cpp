class Solution {
public:
    int tribonacci(int n) {
        int f0 = 0;
        int f1 = 1;
        int f2 = 1;
      if (n==0)
        return f0;
      if (n==1)
        return f1;
      if (n==2)
        return f2;
      int temp = 0;
      int ans = 0;
      for (int i = 3; i<=n; i++){
        temp = f0 + f1 + f2;
        f0 = f1;
        f1 = f2;
        f2 = temp;
        ans = temp;
      }
      return ans;
    }
};