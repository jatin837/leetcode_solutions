#define ll unsigned long long int
class Solution {
public:
  vector<long long> kthPalindrome(vector<int>& qs, int n) {
    long long max_possible=0;
    int j = n;
    while(j--)
      max_possible = max_possible*10 + 9;
    
    long long k = (n-1)>>1;
    long long m = 1;
    
    while(k--)
      m = m*10;
    
    vector<long long> res;

    for(auto q:qs){
      ll num = m;
      num = num+(q-1);
      long long b;
      if(n%2==1)
        b = num/10;
      else
        b = num;
      while(b){
        num = num*10 + b%10;
        b = b/10;
      }
      if(num>max_possible)
        res.push_back(-1);
      else
        res.push_back(num);
    }
    return res;
  }
};