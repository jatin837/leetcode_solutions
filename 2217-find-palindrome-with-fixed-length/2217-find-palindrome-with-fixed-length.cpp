#define ll unsigned long long int
class Solution {
public:
  vector<long long> kthPalindrome(vector<int>& q, int n) {
    long long h=0;
    int j = n;
    while(j--)
      h = h*10 + 9;
    long long k;
    if(n%2==0)
      k = n/2 - 1;
    else
      k = n/2;
    long long m = 1;
    while(k--)
      m = m*10;
    
    vector<long long> res;

    for(int i=0; i<q.size(); i++){
      ll num = m;
      num = num+(q[i]-1);
      long long b;

      if(n%2==1)
        b = num/10;
      else
        b = num;
      while(b){
        num = num*10 + b%10;
        b = b/10;
      }
      if(num>h)
        res.push_back(-1);
      else
        res.push_back(num);
    }
    return res;
  }
};