class Solution {
public:
    bool detectCapitalUse(string word) {
      if(word.size() == 1)
        return true;
      for(int i=2; i<word.size(); i++)
        if(islower(word[i]) != islower(word[i-1]))
          return false;
      if(islower(word[0]) == islower(word[1]))
        return true;
      return isupper(word[0]);
    }
};