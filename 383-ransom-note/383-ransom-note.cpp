class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      int given[26]={0}, required[26]={0};
      for(auto ch:magazine)
        given[ch-'a']++;
      for(char ch:ransomNote){
        if(given[ch-'a'] <= required[ch-'a'])
          return false;
        required[ch-'a']++;
      }
      return true;
    }
};