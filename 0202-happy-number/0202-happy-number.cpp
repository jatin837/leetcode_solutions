class Solution {
public:
  unordered_set<int>seen;
  bool isHappy(int n) {
    seen.insert(n);
    int sum = 0;
    while(n){
      int d = n%10;
      sum += d*d;
      n/=10;
    }
    if(sum == 1)
      return true;
    if(seen.count(sum))
      return false;
    return isHappy(sum);
  }
};