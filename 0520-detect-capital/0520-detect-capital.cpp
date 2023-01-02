class Solution {
public:
    bool detectCapitalUse(string word) {
      char ch1 = word[0];
      char ch2 = word[1];
      if(word.size() == 1)
        return true;
      if(isupper(ch1) and isupper(ch2)){
        for(int i=2; i<word.size(); i++){
          if(islower(word[i]))
            return false;
        }
      }else if(isupper(ch1) and islower(ch2)){
        for(int i=2; i<word.size(); i++){
          if(isupper(word[i]))
            return false;
        }
      }else if(islower(ch1) and islower(ch2)){
        for(int i=2; i<word.size(); i++)
          if(isupper(word[i]))
            return false;
      }else if(islower(ch1) and isupper(ch2))
        return false;
      return true;
    }
};