class Solution {
public:
    long long dp[1001] = {-1};
    long long power(int n){
      if(n == 1)
        return 0;
      if(n%2)
        return 1+power(3*n + 1);
      return 1+power(n/2);
    }
    int getKth(int lo, int hi, int k) {
      vector<int>v;
      for(int i=lo; i<=hi; i++)
        v.push_back(i);
      sort(v.begin(), v.end(), [&](int &a, int &b){
        if(power(a)==power(b))
          return a<=b;
        return power(a) < power(b);
      });
      return v[k-1];
    }
};