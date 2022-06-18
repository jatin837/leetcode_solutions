class Solution {
public:
    bool check(string &s, int b, int e){
      while(b<e){
        if(s[b] != s[e])
          return false;
        b++;e--;
      }
      return true;
    }
    bool validPalindrome(string s) {
      int b = 0;
      int e = s.length()-1;
      bool deleted = false;
      while(b<e){
        if(s[b] == s[e]){
          b++;e--;
        }else{
          return check(s, b+1, e) or check(s, b, e-1);
        }
      }
      return true;
    }
};