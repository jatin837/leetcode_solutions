#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int f1 = 1;
    int f2 = 2;
    int temp = 0;
    int ans = 0;
    if (n==1)
      return 1;
    if (n==2)
      return 2;
    for (int i=2; i<n; i++){
      temp = f1 + f2;
      f1 = f2;
      f2 = temp;
      ans = temp;
      temp = 0;
    }
    return ans;
  }
};
