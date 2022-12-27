class Solution {
public:
  int balancedStringSplit(string s) {
    unordered_map<int, int>cnt;
    cnt[0] = 1;
    int sum = 0;
    int ret = 0;
    for(char ch:s){
      if(ch == 'L')
        sum -= 1;
      else
        sum += 1;
      ret += cnt[-sum];
    }
    return ret;
  }
};