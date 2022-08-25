class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char, int>given, required;
      for(auto ch:magazine)
        given[ch]++;
      for(char ch:ransomNote){
        if(given[ch] <= required[ch])
          return false;
        required[ch]++;
      }
      return true;
    }
};