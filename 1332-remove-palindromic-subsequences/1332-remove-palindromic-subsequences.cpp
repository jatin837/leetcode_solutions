class Solution {
public:
    int removePalindromeSub(string s) {
      if(s.length() == 0)
        return 0;
      if(s.length() == 1)
        return 1;
      for(int i=0; i<s.length()>>1; i++){
        if(s[i] != s[s.length()-1-i])
          return 2;
      }
      return 1;
    }
};