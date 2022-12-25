class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char, int>mp;
      int ret = 0;
      for(char ch:s)
        mp[ch]++;
      bool flag = false;
      for(auto [k, v]:mp){
        ret += (v/2)*2;
        if(v%2)
          flag = true;
      }
      return ret+int(flag);
    }
};