class Solution {
public:
    long long numberOfWays(string s) {
      long long n = s.length();
      vector<long long> b(n);
      vector<long long> a(n);
      b[0] = 0;
      a[n-1] = 0;
      for(int i=1; i<n; i++){
          b[i] = b[i-1] + int(s[i-1] == '0');
          a[n-i-1] = a[n-i] + int(s[n-i] == '0');
      }
      long long ans = 0;
      for(int i=1; i<n-1; i++){
        if (s[i] == '1'){
          ans += b[i]*a[i];
        }else{
          ans += (i-b[i])*(n-i-1-a[i]);
        }
      }
      return ans;
    }
};