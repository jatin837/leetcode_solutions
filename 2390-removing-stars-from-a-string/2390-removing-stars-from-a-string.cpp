class Solution {
public:
    string removeStars(string s) {
      int j=0;
      for(int i=0; i<s.length(); i++)
        if(s[i] == '*')
          j--;
        else
          s[j++] = s[i];
      return s.substr(0, j);
    }
};