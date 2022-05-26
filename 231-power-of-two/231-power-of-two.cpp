#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
      if(n<=0)
        return false;
      return __builtin_popcount(n&INT_MAX) == 1; 
    }
};