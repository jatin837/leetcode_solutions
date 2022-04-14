#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int ammount) {
      int n = coins.size();
      
      vector<int>dp(ammount+1, 1e8);
      
      if(ammount == 0)
        return 0;
      
      for(auto c:coins)
        if(c<=ammount)
          dp[c] = 1;
      
      for(int i=1; i<ammount+1; i++){
        for(auto c:coins){
          if(i-c >= 0)
            dp[i] = min(dp[i], dp[i-c] + 1);
        }
      }
      return (dp[ammount] == 1e8)?-1:dp[ammount];
    }
};