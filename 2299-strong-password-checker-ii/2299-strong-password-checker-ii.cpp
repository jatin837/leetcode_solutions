class Solution {
public:
    bool strongPasswordCheckerII(string password) {
      if(password.length() < 8)
        return false; 
      bool lc = false, uc = false, d = false, sc = false;
      for(int i=0; i<password.length(); i++){
        char ch = password[i];
        if(i > 0 and ch == password[i-1])
          return false;
        if(isalpha(ch)){
          if(islower(ch))
            lc = true;
          else
            uc = true;
        }else if(isdigit(ch))
          d = true;
        else
          sc = true;
      }
      return lc and sc and uc and d;
    }
};