class Solution {
public:
    int numSquares(int ammount) {
      
      vector<int>coins;
      
      int i=1;
      while(i*i<=ammount)
        coins.push_back(i*(i++));
      
      int n = coins.size();
      
      for(auto c:coins)
        cout<<c<<' ';
      cout<<'\n';
      
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
      for(auto d:dp){
        cout<<d<<' ';
      }
      cout<<'\n';
      return (dp[ammount] == 1e8)?-1:dp[ammount];
    }
};